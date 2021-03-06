/**
 * =============================================================================
 * Zombie Plague 8.x Copyright (C) 2015-2018 Nikita Ushakov (Ireland, Dublin).
 * =============================================================================
 *
 * This file is part of the Zombie Plague Core.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 **/

#if defined _zombieplaguemod_included
 #endinput
#endif
#define _zombieplaguemod_included

#if !defined _sdkhooks_included
  #include <sdkhooks>
#endif

/**
 * @section Lenth of usual strings.
 **/
#define SMALL_LINE_LENGTH   32
#define NORMAL_LINE_LENGTH  64
#define BIG_LINE_LENGTH     128
/**
 * @endsection
 **/
 
/**
 * @section Number of player classes.
 **/
enum ZPClassType
{
    TYPE_ZOMBIE,            /**< Make a zombie */
    TYPE_NEMESIS,           /**< Make a nemesis */
    TYPE_SURVIVOR,          /**< Make a survivor */
    TYPE_HUMAN              /**< Make a human */
};
/**
 * @endsection
 **/

/**
 * @section Damage type values.
 **/
#define DAMAGE_NO           0
#define DAMAGE_EVENTS_ONLY  1    //! Call damage functions, but don't modify health
#define DAMAGE_YES          2
#define DAMAGE_AIM          3
/**
 * @endsection
 **/
 
/**
 * @section Water levels.
 **/
#define WLEVEL_CSGO_DRY     0
#define WLEVEL_CSGO_FEET    1
#define WLEVEL_CSGO_HALF    2
#define WLEVEL_CSGO_FULL    3
/**
 * @endsection
 **/
 
/**
 * @section Explosion flags.
 **/
#define EXP_NODAMAGE                (1<<0)
#define EXP_REPEATABLE              (1<<1)
#define EXP_NOFIREBALL              (1<<2)
#define EXP_NOSMOKE                 (1<<3)
#define EXP_NODECAL                 (1<<4)
#define EXP_NOSPARKS                (1<<5)
#define EXP_NOSOUND                 (1<<6)
#define EXP_RANDOMORIENTATION       (1<<7)
#define EXP_NOFIREBALLSMOKE         (1<<8)
#define EXP_NOPARTICLES             (1<<9)
#define EXP_NODLIGHTS               (1<<10)
#define EXP_NOCLAMPMIN              (1<<11)
#define EXP_NOCLAMPMAX              (1<<12)
/**
 * @endsection
 **/
 
/**
 * @section Weapon addon bits.
 **/
#define CSAddon_NONE                0
#define CSAddon_Flashbang1          (1<<0)
#define CSAddon_Flashbang2          (1<<1)
#define CSAddon_HEGrenade           (1<<2)
#define CSAddon_SmokeGrenade        (1<<3)
#define CSAddon_C4                  (1<<4)
#define CSAddon_DefuseKit           (1<<5)
#define CSAddon_PrimaryWeapon       (1<<6)
#define CSAddon_SecondaryWeapon     (1<<7)
#define CSAddon_Holster             (1<<8) 
#define CSAddon_Decoy               (1<<9)
#define CSAddon_Knife               (1<<10)
#define CSAddon_FaceMask            (1<<11) // I'am guess
#define CSAddon_TaGrenade           (1<<12)
/**
 * @endsection
 **/
 
/**
 * @section Hud elements flags.
 **/
#define HIDEHUD_WEAPONSELECTION     (1<<0)   // Hide ammo count & weapon selection
#define HIDEHUD_FLASHLIGHT          (1<<1)
#define HIDEHUD_ALL                 (1<<2)
#define HIDEHUD_HEALTH              (1<<3)   // Hide health & armor / suit battery
#define HIDEHUD_PLAYERDEAD          (1<<4)   // Hide when local player's dead
#define HIDEHUD_NEEDSUIT            (1<<5)   // Hide when the local player doesn't have the HEV suit
#define HIDEHUD_MISCSTATUS          (1<<6)   // Hide miscellaneous status elements (trains, pickup history, death notices, etc)
#define HIDEHUD_CHAT                (1<<7)   // Hide all communication elements (saytext, voice icon, etc)
#define HIDEHUD_CROSSHAIR           (1<<8)   // Hide crosshairs
#define HIDEHUD_VEHICLE_CROSSHAIR   (1<<9)   // Hide vehicle crosshair
#define HIDEHUD_INVEHICLE           (1<<10)
#define HIDEHUD_BONUS_PROGRESS      (1<<11)  // Hide bonus progress display (for bonus map challenges)
/**
 * @endsection
 **/
 
/**
 * @section Entity effects flags.
 **/
#define EF_BONEMERGE                (1<<0)     // Performs bone merge on client side
#define EF_BRIGHTLIGHT              (1<<1)     // DLIGHT centered at entity origin
#define EF_DIMLIGHT                 (1<<2)     // Player flashlight
#define EF_NOINTERP                 (1<<3)     // Don't interpolate the next frame
#define EF_NOSHADOW                 (1<<4)     // Disables shadow
#define EF_NODRAW                   (1<<5)     // Prevents the entity from drawing and networking
#define EF_NORECEIVESHADOW          (1<<6)     // Don't receive shadows
#define EF_BONEMERGE_FASTCULL       (1<<7)     // For use with EF_BONEMERGE. If this is set, then it places this ents origin at its parent and uses the parent's bbox + the max extents of the aiment. Otherwise, it sets up the parent's bones every frame to figure out where to place the aiment, which is inefficient because it'll setup the parent's bones even if the parent is not in the PVS.
#define EF_ITEM_BLINK               (1<<8)     // Makes the entity blink
#define EF_PARENT_ANIMATES          (1<<9)     // Always assume that the parent entity is animating
#define EF_FOLLOWBONE               (1<<10)    
/**
 * @endsection
 **/

/**
 * @section Weapon slots.
 **/
enum
{ 
    SLOT_INVALID = -1,        /** Used as return value when an weapon doens't exist. */
    
    SLOT_PRIMARY,             /** Primary slot */
    SLOT_SECONDARY,           /** Secondary slot */
    SLOT_MELEE,               /** Melee slot */
    SLOT_EQUIPMENT,           /** Equipment slot */  
    SLOT_C4                   /** C4 slot */  
};
/**
 * @endsection
 **/
 
/**
 * @section Solid types.
 **/
enum /*SolidType_t*/
{
    SOLID_NONE      = 0,    // no solid model
    SOLID_BSP       = 1,    // a BSP tree
    SOLID_BBOX      = 2,    // an AABB
    SOLID_OBB       = 3,    // an OBB (not implemented yet)
    SOLID_OBB_YAW   = 4,    // an OBB, constrained so that it can only yaw
    SOLID_CUSTOM    = 5,    // Always call into the entity for tests
    SOLID_VPHYSICS  = 6,    // solid vphysics object, get vcollide from the model and collide with that
    SOLID_LAST,
};
/**
 * @endsection
 **/
 
/**
 * @section Collision groups.
 **/
enum /*Collision_Group_t*/
{
    COLLISION_GROUP_NONE  = 0,
    COLLISION_GROUP_DEBRIS,             // Collides with nothing but world and static stuff
    COLLISION_GROUP_DEBRIS_TRIGGER,     // Same as debris, but hits triggers
    COLLISION_GROUP_INTERACTIVE_DEBRIS, // Collides with everything except other interactive debris or debris
    COLLISION_GROUP_INTERACTIVE,        // Collides with everything except interactive debris or debris
    COLLISION_GROUP_PLAYER,
    COLLISION_GROUP_BREAKABLE_GLASS,
    COLLISION_GROUP_VEHICLE,
    COLLISION_GROUP_PLAYER_MOVEMENT,    // For HL2, same as Collision_Group_Player
    
    COLLISION_GROUP_NPC,                // Generic NPC group
    COLLISION_GROUP_IN_VEHICLE,         // for any entity inside a vehicle
    COLLISION_GROUP_WEAPON,             // for any weapons that need collision detection
    COLLISION_GROUP_VEHICLE_CLIP,       // vehicle clip brush to restrict vehicle movement
    COLLISION_GROUP_PROJECTILE,         // Projectiles!
    COLLISION_GROUP_DOOR_BLOCKER,       // Blocks entities not permitted to get near moving doors
    COLLISION_GROUP_PASSABLE_DOOR,      // Doors that the player shouldn't collide with
    COLLISION_GROUP_DISSOLVING,         // Things that are dissolving are in this group
    COLLISION_GROUP_PUSHAWAY,           // Nonsolid on client and server, pushaway in player code

    COLLISION_GROUP_NPC_ACTOR,          // Used so NPCs in scripts ignore the player.
    COLLISION_GROUP_NPC_SCRIPTED,       // USed for NPCs in scripts that should not collide with each other
    
    LAST_SHARED_COLLISION_GROUP
};
/**
 * @endsection
 **/

/**
 * @section Solid flags.
 **/
enum /*SolidFlags_t*/
{
    FSOLID_CUSTOMRAYTEST        = 0x0001,   // Ignore solid type + always call into the entity for ray tests
    FSOLID_CUSTOMBOXTEST        = 0x0002,   // Ignore solid type + always call into the entity for swept box tests
    FSOLID_NOT_SOLID            = 0x0004,   // Are we currently not solid?
    FSOLID_TRIGGER              = 0x0008,   // This is something may be collideable but fires touch functions
                                            // even when it not collideable (when the FSOLID_NOT_SOLID flag is set)
    FSOLID_NOT_STANDABLE        = 0x0010,   // You can't stand on this
    FSOLID_VOLUME_CONTENTS      = 0x0020,   // Contains volumetric contents (like water)
    FSOLID_FORCE_WORLD_ALIGNED  = 0x0040,   // Forces the collision rep to be world-aligned even if it SOLID_BSP or SOLID_VPHYSICS
    FSOLID_USE_TRIGGER_BOUNDS   = 0x0080,   // Uses a special trigger bounds separate from the normal OBB
    FSOLID_ROOT_PARENT_ALIGNED  = 0x0100,   // Collisions are defined in root parent local coordinate space
    FSOLID_TRIGGER_TOUCH_DEBRIS = 0x0200,   // This trigger will touch debris objects

    FSOLID_MAX_BITS    = 10
};
/**
 * @endsection
 **/
 
#include "zombieplague/menus.inc"
#include "zombieplague/sounds.inc"
#include "zombieplague/weapons.inc"
#include "zombieplague/costumes.inc"
#include "zombieplague/gamemodes.inc"
#include "zombieplague/hitgroups.inc"
#include "zombieplague/extraitems.inc"
#include "zombieplague/humanclasses.inc" 
#include "zombieplague/zombieclasses.inc"


//*********************************************************************
//*                       CORE MAIN FORWARDS                          *
//*********************************************************************

/**
 * @brief Called when a client became a zombie/nemesis.
 * 
 * @param victimIndex       The client index.
 * @param attackerIndex     The attacker index.
 * @param nemesisMode       Indicates that client will be a nemesis.
 * @param respawnMode       Indicates that infection was on spawn.
 *
 * @noreturn
 **/
forward void ZP_OnClientInfected(int clientIndex, int attackerIndex, bool nemesisMode, bool respawnMode);

/**
 * @brief Called when a client became a human/survivor.
 * 
 * @param clientIndex       The client index.
 * @param survivorMode      Indicates that client will be a survivor.
 * @param respawnMode       Indicates that humanizing was on spawn.
 *
 * @noreturn
 **/
forward void ZP_OnClientHumanized(int clientIndex, bool survivorMode, bool respawnMode);

/**
 * @brief Called when a client take a fake damage.
 * 
 * @param clientIndex       The client index.
 * @param attackerIndex     The attacker index. (Not validated!)
 * @param inflictorIndex    The inflictor index. (Not validated!)
 * @param damageAmount      The amount of damage inflicted.
 * @param damageType        The ditfield of damage types.
 * @param weaponIndex       The weapon index or -1 for unspecified.
 *
 * @noreturn
 **/
forward void ZP_OnClientDamaged(int clientIndex, int attackerIndex, int inflictorIndex, float &damageAmount, int damageType, int weaponIndex);

/**
 * @brief Called when a client use a skill.
 * 
 * @param clientIndex       The client index.
 *
 * @return                  Plugin_Handled or Plugin_Stop to block using skill. Anything else
 *                              (like Plugin_Continue) to allow use.
 **/
forward Action ZP_OnClientSkillUsed(int clientIndex);

/**
 * @brief Called when a skill duration is over.
 * 
 * @param clientIndex       The client index.
 *
 * @noreturn
 **/
forward void ZP_OnClientSkillOver(int clientIndex);

/**
 * @brief Called after a round is started.
 *
 * @param modeIndex         The mode index. 
 *
 * @noreturn
 **/
forward void ZP_OnZombieModStarted(int modeIndex);

/**
 * @brief Called after a core is loaded.
 *
 * @noreturn
 **/
forward void ZP_OnEngineExecute(/*void*/);

//*********************************************************************
//*                       CORE MAIN NATIVES                           *
//*********************************************************************

/**
 * @brief Applies fake damage to an entity. 
 *
 * @note Apply trace knockback of the attacker weapon id only with DMG_NEVERGIB and weaponIndex,
 *             for other custom knockback use FakeCreateKnockBack() native.
 *
 * @param clientIndex       The client index.
 * @param attackerIndex     The attacker index.
 * @param damageAmount      The amount of damage inflicted.
 * @param damageType        (Optional) The ditfield of damage types.
 * @param weaponIndex       (Optional) The weapon index or -1 for unspecified.
 *
 * @noreturn
 **/
native void ZP_TakeDamage(int clientIndex, int attackerIndex, float damageAmount, int damageType = DMG_GENERIC, int weaponIndex = INVALID_ENT_REFERENCE);

/**
 * @brief Set a round termination.
 *
 * @param reason            Reason the round has ended.
 * 
 * @noreturn
 **/
native void ZP_TerminateRound(int reason);

/**
 * Update a entity transmit state.
 *
 * @param entityIndex       The entity index.
 *
 * @noreturn
 **/
native void ZP_UpdateTransmitState(int entityIndex);

/**
 * Validate the attachment on the entity.
 *
 * @param entityIndex       The entity index.
 * @param attach            The attachment name.
 *
 * @return                  True or false.
 **/
native bool ZP_LookupAttachment(int entityIndex, char[] attach);

/**
 * Gets the attachment of the entity.
 *
 * @param entityIndex       The entity index.
 * @param attach            The attachment name.
 * @param origin            The origin ouput.
 * @param angle             The angle ouput.
 *
 * @noreturn
 **/
native void ZP_GetAttachment(int entityIndex, char[] attach, float origin[3], float angles[3]);

/**
 * @brief Returns whether a player is in group or not.
 *
 * @param clientIndex       The client index.
 * @param group             The group name.
 *  
 * @return                  True or false.
 **/
native bool ZP_IsPlayerInGroup(int clientIndex, char[] group);

/**
 * @brief Returns true if the player is a zombie, false if not. 
 *
 * @param clientIndex       The client index.
 *  
 * @return                  True or false.
 **/
native bool ZP_IsPlayerZombie(int clientIndex);

/**
 * @brief Returns true if the player is a human, false if not.
 *
 * @param clientIndex       The client index.
 *  
 * @return                  True or false.
 **/
native bool ZP_IsPlayerHuman(int clientIndex);

/**
 * @brief Returns true if the player is a nemesis, false if not. (In addition, Nemesis always have ZP_IsPlayerZombie() native)
 *
 * @param clientIndex       The client index.
 *  
 * @return                  True or false.
 **/
native bool ZP_IsPlayerNemesis(int clientIndex);

/**
 * @brief Returns true if the player is a survivor, false if not.
 *
 * @param clientIndex       The client index.
 *  
 * @return                  True or false.
 **/
native bool ZP_IsPlayerSurvivor(int clientIndex);

/**
 * @brief Returns true if the player use a zombie skill, false if not. 
 *
 * @param clientIndex       The client index.
 *  
 * @return                  True or false.
 **/
native bool ZP_IsPlayerUseZombieSkill(int clientIndex);

/**
 * @brief Force to respawn a player.
 *
 * @param clientIndex       The client index.
 *  
 * @noreturn
 **/
native void ZP_ForceClientRespawn(int clientIndex);

/**
 * @brief Force to switch a player class.
 *
 * @param clientIndex       The client index.
 * @param attackerIndex     (Optional) The attacker index.
 * @param typeIndex         The class type. See enum ZPClassType.
 *  
 * @noreturn
 **/
native void ZP_SwitchClientClass(int clientIndex, int attackerIndex = 0, ZPClassType typeIndex);

/**
 * @brief Gets the player amount of ammopacks.
 *
 * @param clientIndex       The client index.
 *  
 * @return                  The number of ammopacks.
 **/
native int ZP_GetClientAmmoPack(int clientIndex);

/**
 * @brief Sets the player amount of ammopacks.
 *
 * @param clientIndex       The client index.
 * @param amountAmmo        The number of ammopacks.
 *  
 * @noreturn
 **/
native void ZP_SetClientAmmoPack(int clientIndex, int amountAmmo);

/**
 * @brief Gets the player amount of previous ammopacks spended.
 *
 * @param clientIndex       The client index.
 *  
 * @return                  The number of ammopacks.
 **/
native int ZP_GetClientLastBought(int clientIndex);

/**
 * @brief Sets the player amount of ammopacks spending.
 *
 * @param clientIndex       The client index.
 * @param amountAmmo        The number of ammopacks.
 *  
 * @noreturn
 **/
native void ZP_SetClientLastBought(int clientIndex, int amountAmmo);

/**
 * @brief Gets the player level.
 *
 * @param clientIndex       The client index.
 *  
 * @return                  The number of level.
 **/
native int ZP_GetClientLevel(int clientIndex);

/**
 * @brief Sets the player level.
 *
 * @param clientIndex       The client index.
 * @param amountLevel       The number of level.
 *  
 * @noreturn
 **/
native int ZP_SetClientLevel(int clientIndex, int amountLevel);

/**
 * @brief Gets the player exp.
 *
 * @param clientIndex       The client index.
 *  
 * @return                  The number of exp.
 **/
native int ZP_GetClientExp(int clientIndex);

/**
 * @brief Sets the player exp.
 *
 * @param clientIndex       The client index.
 * @param amountExp         The number of exp.
 *  
 * @noreturn
 **/
native int ZP_SetClientExp(int clientIndex, int amountExp);

/**
 * @brief Gets the last player disconnected time.
 *
 * @param clientIndex       The client index.
 *  
 * @return                  The 32bit timestamp. (Number of seconds since unix epoch)
 **/
native int ZP_GetClientTime(int clientIndex);

//*********************************************************************
//*                       CORE USEFUL NATIVES                         *
//*********************************************************************

/**
 * @brief Gets the new round state.
 *
 * @return                  True or false.
 **/
native bool ZP_IsNewRound();

/**
 * @brief Gets the end round state.
 *
 * @return                  True or false.
**/
native bool ZP_IsEndRound();

/**
 * @brief Gets the new round state.
 *
 * @return                  True or false.
 **/
native bool ZP_IsStartedRound();

/**
 * @brief Gets the number of round.
 *
 * @return                  The round counter.
 **/
native int ZP_GetNumberRound();

/**
 * @brief Gets amount of total humans.
 * 
 * @return                  The amount of total humans.
 **/
native int ZP_GetHumanAmount();

/**
 * @brief Gets amount of total zombies.
 *
 * @return                  The amount of total zombies.
 **/
native int ZP_GetZombieAmount();

/**
 * @brief Gets amount of total alive players.
 *
 * @return                  The amount of total alive players.
 **/
native int ZP_GetAliveAmount();

/**
 * @brief Gets amount of total playing players.
 *
 * @return                   The amount of total playing players.
 **/
native int ZP_GetPlayingAmount();

/**
 * @brief Gets index of the random human.
 *
 * @return                  The index of random human.
 **/
native int ZP_GetRandomHuman();

/**
 * @brief Gets index of the random zombie.
 *
 * @return                  The index of random zombie.
 **/
native int ZP_GetRandomZombie();

/**
 * @brief Gets index of the random survivor.
 *
 * @return                  The index of random survivor.
 **/
native int ZP_GetRandomSurvivor();

/**
 * @brief Gets index of the random nemesis.
 *
 * @return                  The index of random nemesis.
 **/
native int ZP_GetRandomNemesis();

//*********************************************************************
//*                       OTHER USEFUL STOCKS                         *
//*********************************************************************

/**
 * @brief Returns true if the player is connected and alive, false if not.
 *
 * @param clientIndex       The client index.
 * @param aliveness         (Optional) Set to true to validate that the client is alive, false to ignore.
 *  
 * @return                  True or false.
 **/
stock bool IsPlayerExist(const int clientIndex, const bool aliveness = true)
{
    // If client isn't valid, then stop
    if(clientIndex <= 0 || clientIndex > MaxClients)
    {
        return false;
    }

    // If client isn't connected, then stop
    if(!IsClientConnected(clientIndex))
    {
        return false;
    }

    // If client isn't in game, then stop
    if(!IsClientInGame(clientIndex) || IsClientInKickQueue(clientIndex))
    {
        return false;
    }

    // If client is TV, then stop
    if(IsClientSourceTV(clientIndex))
    {
        return false;
    }

    // If client isn't alive, then stop
    if(aliveness && !IsPlayerAlive(clientIndex))
    {
        return false;
    }

    // If client exist
    return true;
}

/**
 * @brief Create a particle entity.
 * 
 * @param parentIndex       The parent index.
 * @param vPosition         (Optional) The origin of the entity.
 * @param sAttach           (Optional) The attachment name.
 * @param sType             The type of the particle.
 * @param flDurationTime    The duration of light.
 * @return                  The entity index.
 **/
stock int FakeCreateParticle(const int parentIndex, const float vPosition[3] = NULL_VECTOR, const char[] sAttach = "", const char[] sType, const float flDurationTime)
{
    // Create an attach particle entity
    int entityIndex = CreateEntityByName("info_particle_system");
    
    // If entity isn't valid, then skip
    if(entityIndex != INVALID_ENT_REFERENCE)
    {
        // Dispatch main values of the entity
        DispatchKeyValue(entityIndex, "start_active", "1");
        DispatchKeyValue(entityIndex, "effect_name", sType);
        
        // Spawn the entity into the world
        DispatchSpawn(entityIndex);

        // Sets parent to the entity
        SetVariantString("!activator");
        AcceptEntityInput(entityIndex, "SetParent", parentIndex, entityIndex);
        SetEntPropEnt(entityIndex, Prop_Send, "m_hOwnerEntity", parentIndex);
        
        // Sets attachment to the entity
        if(strlen(sAttach))
        { 
            SetVariantString(sAttach); 
            AcceptEntityInput(entityIndex, "SetParentAttachment", parentIndex, entityIndex);
        }
        else
        {
            // Spawn the entity
            DispatchKeyValueVector(entityIndex, "origin", vPosition);
        }
        
        // Activate the entity
        ActivateEntity(entityIndex);
        AcceptEntityInput(entityIndex, "Start");
        
        // Initialize variable
        static char sTime[SMALL_LINE_LENGTH];
        Format(sTime, sizeof(sTime), "OnUser1 !self:kill::%f:1", flDurationTime);
        
        // Sets modified flags on the entity
        SetVariantString(sTime);
        AcceptEntityInput(entityIndex, "AddOutput");
        AcceptEntityInput(entityIndex, "FireUser1");
    }
    
    // Return on the success
    return entityIndex;
}

/**
 * @brief Create an fake entity.
 * 
 * @param vPosition         The origin of the entity.
 * @param flDurationTime    The duration of life.
 * @return                  The entity index.
 **/
stock int FakeCreateEntity(const float vPosition[3], const float flDurationTime)
{
    // Create an fake info entity
    int entityIndex = CreateEntityByName("info_target");

    // If entity isn't valid, then skip
    if(entityIndex != INVALID_ENT_REFERENCE)
    {
        // Spawn the entity into the world
        DispatchSpawn(entityIndex);

        // Spawn the entity
        DispatchKeyValueVector(entityIndex, "origin", vPosition);

        // Initialize variable
        static char sTime[SMALL_LINE_LENGTH];
        Format(sTime, sizeof(sTime), "OnUser1 !self:kill::%f:1", flDurationTime);

        // Sets modified flags on the entity
        SetVariantString(sTime);
        AcceptEntityInput(entityIndex, "AddOutput");
        AcceptEntityInput(entityIndex, "FireUser1");
    }

    // Return on the success
    return entityIndex;
}

/**
 * @brief Shake a client screen with specific parameters.
 * 
 * @param clientIndex       The client index.
 * @param flAmplitude       The amplitude of shake.
 * @param flFrequency       The frequency of shake.
 * @param flDuration        The duration of shake in the seconds.
 **/
stock void FakeCreateShakeScreen(const int clientIndex, const float flAmplitude, const float flFrequency, const float flDuration)
{
    // Create message
    Handle hShake = StartMessageOne("Shake", clientIndex);

    // Validate message
    if(hShake != INVALID_HANDLE)
    {
        // Write shake information to message handle
        PbSetInt(hShake,   "command", 0);
        PbSetFloat(hShake, "local_amplitude", flAmplitude);
        PbSetFloat(hShake, "frequency", flFrequency);
        PbSetFloat(hShake, "duration", flDuration);

        // End usermsg and send to client
        EndMessage();
    }
}

/**
 * @brief Fade a client screen with specific parameters.
 * 
 * @param clientIndex       The client index.
 * @param flDuration        The duration of fade in the seconds.
 * @param flHoldTime        The holding time of fade in the seconds.
 * @param iFlags            The flags.
 * @param vColor            The array with RGB color.
 **/
stock void FakeCreateFadeScreen(const int clientIndex, const float flDuration, const float flHoldTime, const int iFlags, const int vColor[4])
{
    // Create message
    Handle hFade = StartMessageOne("Fade", clientIndex);

    // Validate message
    if(hFade != INVALID_HANDLE)
    {
        // Write shake information to message handle
        PbSetInt(hFade, "duration", RoundToNearest(flDuration * 1000.0)); 
        PbSetInt(hFade, "hold_time", RoundToNearest(flHoldTime * 1000.0)); 
        PbSetInt(hFade, "flags", iFlags); 
        PbSetColor(hFade, "clr", vColor); 

        // End usermsg and send to client
        EndMessage();
    }
}

/**
 * @brief Push a client with specific parameters.
 * 
 * @param clientIndex       The client index.
 * @param vVelocity         The velocity vector.
 * @param flDistance        The distance amount.
 * @param flPower           The power amount.
 * @param flRadius          The radius amount.
**/
stock void FakeCreateKnockBack(const int clientIndex, float vVelocity[3], const float flDistance, const float flPower, const float flRadius)
{
    // Calculate the push power
    float flKnockBack = flPower * (1.0 - (flDistance / flRadius));

    // Normalize the vector (equal magnitude at varying distances)
    NormalizeVector(vVelocity, vVelocity);

    // Apply the magnitude by scaling the vector
    ScaleVector(vVelocity, SquareRoot((flKnockBack * flKnockBack) / ((vVelocity[0] * vVelocity[0]) + (vVelocity[1] * vVelocity[1]) + (vVelocity[2] * vVelocity[2])))); vVelocity[2] * flPower;

    // Push the client
    TeleportEntity(clientIndex, NULL_VECTOR, NULL_VECTOR, vVelocity);
}

/**
 * @brief Dispatch an attached effect.
 * 
 * @param entityIndex       (Optional) The entity index.
 * @param sParticle         (Optional) The particle name.
 * @param sItem             (Optional) The particle item.
 * @param vStart            (Optional) The start origin.
 * @param vEnd              (Optional) The end origin.
 * @param vAngle            (Optional) The angle vector.
 * @param iAttachment       (Optional) The attachment index.
 **/
stock void FakeDispatchEffect(const int entityIndex = 0, const char[] sParticle = "", const char[] sIndex = "", const float vStart[3] = NULL_VECTOR, const float vEnd[3] = NULL_VECTOR, const float vAngle[3] = NULL_VECTOR, const int iAttachment = 0) 
{
    // Dispatch effect
    TE_Start("EffectDispatch");
    if(strlen(sParticle)) TE_WriteNum("m_nHitBox", GetParticleEffectIndex(sParticle));
    if(strlen(sIndex)) TE_WriteNum("m_iEffectName", GetEffectIndex(sIndex));
    TE_WriteFloat("m_vOrigin.x", vEnd[0]);
    TE_WriteFloat("m_vOrigin.y", vEnd[1]);
    TE_WriteFloat("m_vOrigin.z", vEnd[2]);
    TE_WriteFloat("m_vStart.x", vStart[0]);
    TE_WriteFloat("m_vStart.y", vStart[1]);
    TE_WriteFloat("m_vStart.z", vStart[2]);
    TE_WriteVector("m_vAngles", vAngle);
    TE_WriteNum("entindex", entityIndex);
    if(iAttachment) 
    {
        #define PATTACH_WORLDORIGIN 5
        #define PARTICLE_DISPATCH_FROM_ENTITY (1 << 0)
    
        TE_WriteNum("m_nDamageType", PATTACH_WORLDORIGIN);
        TE_WriteNum("m_fFlags", PARTICLE_DISPATCH_FROM_ENTITY); /// https://developer.valvesoftware.com/wiki/SDK_Known_Issues_List_Fixed#Server%20Dispatching%20an%20Attached%20Particle%20Effect
        TE_WriteNum("m_nAttachmentIndex", iAttachment);
    }
}

/**
 * @brief Searches for the index of a given string in a dispatch table.
 *
 * @param sEffect           The effect name.
 * @return                  The item index.
 **/
stock int GetEffectIndex(const char[] sEffect)
{
    // Initialize the table index
    static int tableIndex = INVALID_STRING_TABLE;

    // Validate table
    if(tableIndex == INVALID_STRING_TABLE)
    {
        // Searches for a string table
        tableIndex = FindStringTable("EffectDispatch");
    }

    // Searches for the index of a given string in a string table
    int itemIndex = FindStringIndex(tableIndex, sEffect);

    // Validate item
    if(itemIndex != INVALID_STRING_INDEX)
    {
        return itemIndex;
    }

    // Return on the unsuccess
    return 0;
}

/**
 * @brief Searches for the index of a given string in an effect table.
 *
 * @param sEffect           The effect name.
 * @return                  The item index.
 **/
stock int GetParticleEffectIndex(const char[] sEffect)
{
    // Initialize the table index
    static int tableIndex = INVALID_STRING_TABLE;

    // Validate table
    if(tableIndex == INVALID_STRING_TABLE)
    {
        // Searches for a string table
        tableIndex = FindStringTable("ParticleEffectNames");
    }

    // Searches for the index of a given string in a string table
    int itemIndex = FindStringIndex(tableIndex, sEffect);

    // Validate item
    if(itemIndex != INVALID_STRING_INDEX)
    {
        return itemIndex;
    }

    // Return on the unsuccess
    return 0;
}