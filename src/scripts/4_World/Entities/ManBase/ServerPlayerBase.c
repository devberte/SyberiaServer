modded class PlayerBase
{	
	ref CharProfile m_charProfile;
	
	// Sleeping
	float m_sleepingDecTimer;
	float m_sleepingBoostTimer;
	int m_sleepingBoostValue;
	int m_sleepingSoundTimer;
	
	// Adv med
	float m_advMedUpdateTimer;
	float m_painTimer;
	float m_painkillerTime;
	float m_hematomaRegenTimer;
	float m_cuthitRegenTimer;
	float m_stomatchhealTimer;
	bool m_hemologicShock;
	float m_sepsisTime;
	float m_zvirusTimer;
	float m_bullethitRegenTimer;
	float m_knifehitRegenTimer;
	float m_concussionRegenTimer;
	float m_bloodHemostaticTimer;
	float m_hematopoiesisTimer;
	float m_salveEffectTimer;
	float m_adrenalinEffectTimer;
	float m_antibioticsTimer;
	float m_antibioticsStrange;
	float m_influenzaTimer;
	float m_stomatchpoisonTimer;
	float m_radioprotectionTimer;
	float m_antidepresantTimer;
	float m_lastStomatchpoisonHeal;
	
	// Mind state
	float m_mindDegradationForce;
	float m_mindDegradationTime;
	
	// Admin tool
	bool m_freeCamMode = false;
	
	// Skills
	int m_skillsSaveInterval = 0;
	bool m_skillsSaveDirty = false;
	float m_sprintingTime = 0;
	float m_jogingTime = 0;
	vector m_skillsLastPos;
	
	// Zones
	float m_zoneLeaveTimer = 0;
	int m_zoneToxicEffect = 0;
	float m_radiationDose = 0;
	
	override void Init()
	{
		super.Init();
		
		// Sleeping
		m_sleepingDecTimer = 0;
		m_sleepingBoostTimer = 0;
		m_sleepingBoostValue = 0;
		m_sleepingSoundTimer = 0;
		
		// Adv Med
		m_advMedUpdateTimer = 0;
		m_painTimer = 0;
		m_hematomaRegenTimer = 0;
		m_cuthitRegenTimer = 0;
		m_painkillerTime = 0;
		m_stomatchhealTimer = 0;
		m_hemologicShock = false;
		m_sepsisTime = 0;
		m_zvirusTimer = 0;
		m_bullethitRegenTimer = 0;
		m_knifehitRegenTimer = 0;
		m_concussionRegenTimer = 0;
		m_bloodHemostaticTimer = 0;
		m_hematopoiesisTimer = 0;
		m_salveEffectTimer = 0;
		m_adrenalinEffectTimer = 0;
		m_antibioticsTimer = 0;
		m_antibioticsStrange = 0;
		m_influenzaTimer = 0;
		m_stomatchpoisonTimer = 0;
		m_radioprotectionTimer = 0;
		m_antidepresantTimer = 0;
		m_lastStomatchpoisonHeal = 0;
		
		// Mind state
		m_mindDegradationForce = 0;
		m_mindDegradationTime = 0;
		
		// Zones
		m_isPveIntruder = false;
	}
	
	override void OnStoreSave( ParamsWriteContext ctx )
	{
		super.OnStoreSave(ctx);
        
        // VER 100
        ctx.Write( SYBERIA_V100_VERSION );
        ctx.Write( m_sleepingValue );
        ctx.Write( m_sleepingBoostTimer );
        ctx.Write( m_sleepingBoostValue );
        ctx.Write( m_bulletHits );
        ctx.Write( m_knifeHits );
        ctx.Write( m_hematomaHits );
        ctx.Write( m_visceraHit );
        ctx.Write( m_concussionHit );
        ctx.Write( m_painLevel );
        ctx.Write( m_painTimer );
        ctx.Write( m_hematomaRegenTimer );
        ctx.Write( m_cuthitRegenTimer );
        ctx.Write( m_painkillerEffect );
        ctx.Write( m_painkillerTime );
        ctx.Write( m_stomatchpoisonLevel );
		ctx.Write( m_stomatchhealLevel );
        ctx.Write( m_stomatchhealTimer );
        ctx.Write( m_hemologicShock );
        ctx.Write( m_sepsis );
        ctx.Write( m_sepsisTime );
        ctx.Write( m_zombieVirus );
        ctx.Write( m_zvirusTimer );		
        ctx.Write( m_bulletBandage1 );
        ctx.Write( m_bulletBandage2 );
        ctx.Write( m_knifeBandage1 );
        ctx.Write( m_knifeBandage2 );
        ctx.Write( m_bullethitRegenTimer );
        ctx.Write( m_knifehitRegenTimer );
        ctx.Write( m_concussionRegenTimer );
        ctx.Write( m_bloodHemostaticEffect );
        ctx.Write( m_bloodHemostaticTimer );		
        ctx.Write( m_hematopoiesisEffect );		
        ctx.Write( m_hematopoiesisTimer );
        ctx.Write( m_salveEffect );
        ctx.Write( m_salveEffectTimer );		
        ctx.Write( m_adrenalinEffect );
        ctx.Write( m_adrenalinEffectTimer );
        ctx.Write( m_overdosedValue );
		ctx.Write( m_influenzaLevel );
		ctx.Write( m_influenzaTimer );
		ctx.Write( m_antibioticsLevel );
		ctx.Write( m_antibioticsTimer );
		ctx.Write( m_antibioticsStrange );
		ctx.Write( m_stomatchpoisonTimer );
		ctx.Write( m_mindStateValue );
		ctx.Write( m_mindDegradationForce );
		ctx.Write( m_mindDegradationTime );
		
		// VER 100
        ctx.Write( SYBERIA_V101_VERSION );
		ctx.Write( m_radiationSickness );
		ctx.Write( m_radiationDose );
		ctx.Write( m_radioprotectionLevel );
		ctx.Write( m_radioprotectionTimer );
		ctx.Write( m_antidepresantLevel );
		ctx.Write( m_antidepresantTimer );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;
		
        // VER 100
        int syb_ver;
        if(ctx.Read( syb_ver ) && syb_ver == SYBERIA_V100_VERSION)
		{
			// Sleeping
			if(!ctx.Read( m_sleepingValue )) return false;		
			if(!ctx.Read( m_sleepingBoostTimer )) return false;		
			if(!ctx.Read( m_sleepingBoostValue )) return false;
			
			// Adv medicine
			if(!ctx.Read( m_bulletHits )) return false;		
			if(!ctx.Read( m_knifeHits )) return false;		
			if(!ctx.Read( m_hematomaHits )) return false;		
			if(!ctx.Read( m_visceraHit )) return false;		
			if(!ctx.Read( m_concussionHit )) return false;		
			if(!ctx.Read( m_painLevel )) return false;		
			if(!ctx.Read( m_painTimer )) return false;		
			if(!ctx.Read( m_hematomaRegenTimer )) return false;		
			if(!ctx.Read( m_cuthitRegenTimer )) return false;		
			if(!ctx.Read( m_painkillerEffect )) return false;		
			if(!ctx.Read( m_painkillerTime )) return false;		
			if(!ctx.Read( m_stomatchpoisonLevel )) return false;		
			if(!ctx.Read( m_stomatchhealLevel )) return false;	
			if(!ctx.Read( m_stomatchhealTimer )) return false;		
			if(!ctx.Read( m_hemologicShock )) return false;		
			if(!ctx.Read( m_sepsis )) return false;		
			if(!ctx.Read( m_sepsisTime )) return false;		
			if(!ctx.Read( m_zombieVirus )) return false;	
			if(!ctx.Read( m_zvirusTimer )) return false;		
			if(!ctx.Read( m_bulletBandage1 )) return false;		
			if(!ctx.Read( m_bulletBandage2 )) return false;		
			if(!ctx.Read( m_knifeBandage1 )) return false;		
			if(!ctx.Read( m_knifeBandage2 )) return false;		
			if(!ctx.Read( m_bullethitRegenTimer )) return false;		
			if(!ctx.Read( m_knifehitRegenTimer )) return false;		
			if(!ctx.Read( m_concussionRegenTimer )) return false;		
			if(!ctx.Read( m_bloodHemostaticEffect )) return false;		
			if(!ctx.Read( m_bloodHemostaticTimer )) return false;		
			if(!ctx.Read( m_hematopoiesisEffect )) return false;		
			if(!ctx.Read( m_hematopoiesisTimer )) return false;		
			if(!ctx.Read( m_salveEffect )) return false;		
			if(!ctx.Read( m_salveEffectTimer )) return false;		
			if(!ctx.Read( m_adrenalinEffect )) return false;
			if(!ctx.Read( m_adrenalinEffectTimer )) return false;
			if(!ctx.Read( m_overdosedValue )) return false;
			if(!ctx.Read( m_influenzaLevel )) return false;
			if(!ctx.Read( m_influenzaTimer )) return false;
			if(!ctx.Read( m_antibioticsLevel )) return false;
			if(!ctx.Read( m_antibioticsTimer )) return false;
			if(!ctx.Read( m_antibioticsStrange )) return false;
			if(!ctx.Read( m_stomatchpoisonTimer )) return false;
			
			// Mind state
			if(!ctx.Read( m_mindStateValue )) return false;
			m_mindStateLast = m_mindStateValue;
			if(!ctx.Read( m_mindDegradationForce )) return false;
			if(!ctx.Read( m_mindDegradationTime )) return false;
		}
		else
		{
			return false;
		}
		
		if(ctx.Read( syb_ver ) && syb_ver == SYBERIA_V101_VERSION)
		{
			if(!ctx.Read( m_radiationSickness )) return false;
			if(!ctx.Read( m_radiationDose )) return false;
			if(!ctx.Read( m_radioprotectionLevel )) return false;
			if(!ctx.Read( m_radioprotectionTimer )) return false;
			if(!ctx.Read( m_antidepresantLevel )) return false;
			if(!ctx.Read( m_antidepresantTimer )) return false;
		}
		else
		{
			return false;
		}
		
		return true;
	}
	
	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);
		
		if (IsAlive())
		{
			m_advMedUpdateTimer = m_advMedUpdateTimer + deltaTime;
			if (m_advMedUpdateTimer > 0.3)
			{
				OnTickAdvMedicine_Bloodlose(m_advMedUpdateTimer);
				OnTickAdvMedicine_Salve(m_advMedUpdateTimer);
				OnTickAdvMedicine_Regen(m_advMedUpdateTimer);
				OnTickAdvMedicine_Pain(m_advMedUpdateTimer);
				OnTickAdvMedicine_Sepsis(m_advMedUpdateTimer);
				OnTickAdvMedicine_ZVirus(m_advMedUpdateTimer);
				OnTickAdvMedicine_Stomatchheal(m_advMedUpdateTimer);
				OnTickAdvMedicine_Antibiotics(m_advMedUpdateTimer);
				OnTickAdvMedicine_Influenza(m_advMedUpdateTimer);
				//OnTickAdvMedicine_HemorlogicShock(m_advMedUpdateTimer);
				OnTickAdvMedicine_Overdose(m_advMedUpdateTimer);
				OnTickAdvMedicine_HemostatickEffect(m_advMedUpdateTimer);
				OnTickAdvMedicine_HematopoiesisEffect(m_advMedUpdateTimer);
				OnTickAdvMedicine_Adrenalin(m_advMedUpdateTimer);
				OnTickAdvMedicine_Radprotector(m_advMedUpdateTimer);
				OnTickAdvMedicine_Antidepresant(m_advMedUpdateTimer);
				m_advMedUpdateTimer = 0;
			}
			
			m_sleepingDecTimer = m_sleepingDecTimer + deltaTime;
			while (m_sleepingDecTimer > 1.0)
			{
				m_sleepingDecTimer = m_sleepingDecTimer - 1.0;
				OnTickLowHealth();
				OnTickSleeping();
				OnTickMindState();
				OnTickSickCheck();
				OnTickStomatchpoison();
				OnTickUnconsition();
				OnTickSkills();
				OnTickExperience();
				OnTickStethoscope();
				OnTickZones();
				OnTickZoneEffect();
				OnTickDisinfectedHands();
			}
					
			if (m_freeCamMode)
			{
				vector teleportPos = GetPosition();
				teleportPos[1] = GetGame().SurfaceY(teleportPos[0], teleportPos[2]) - 50;
				if ( !GameHelpers.GetPlayerVehicle(this) )
				{
					SetPosition(teleportPos);
				}
			}
		}
	}
	
	private void OnTickDisinfectedHands()
	{
		bool lastValue = m_disinfectedHands;
		
		ItemBase gloves = GetItemOnSlot("Gloves");
		if (gloves && gloves.IsCleanness())
		{			
			m_disinfectedHands = true;
			
			ItemBase itemInHands = GetItemInHands();
			if (itemInHands && !itemInHands.IsCleanness() && Math.RandomFloat01() < 0.001)
			{
				gloves.SetCleanness(0);
				m_disinfectedHands = false;
			}
		}
		else if (!gloves && !HasBloodyHands() && GetModifiersManager().IsModifierActive(eModifiers.MDF_DISINFECTION))
		{
			m_disinfectedHands = true;
		}
		else
		{
			m_disinfectedHands = false;
		}
		
		if (m_disinfectedHands != lastValue)
		{
			SetSynchDirty();
		}
	}
	
	private void OnTickLowHealth()
	{
		bool criticalBlood = GetHealth("GlobalHealth", "Blood") < PlayerConstants.SL_BLOOD_CRITICAL;
		bool criticalHealth = GetHealth("GlobalHealth", "Health") < PlayerConstants.SL_HEALTH_CRITICAL;
		if (criticalBlood || criticalHealth)
		{
			DecreaseHealth("", "Shock", GetSyberiaConfig().m_shockDecrementOnLowHealthAndBlood);
		}
	}
	
	private void OnTickZones()
	{
		PluginZones pluginZones = PluginZones.Cast(GetPlugin(PluginZones));
		if (!pluginZones)
			return;
		
		ref ZoneDefinition currentZone = null;
		vector pos = GetPosition();
		float landPos = GetGame().SurfaceY(pos[0], pos[2]);
		vector pos2d = pos;
		vector zone2d;
		float landDiff;
		pos2d[1] = 0;
		
		if (pluginZones.m_config.m_customZones)
		{
			foreach (ref ZoneDefinition zone : pluginZones.m_config.m_customZones)
			{
				if (zone.m_height < 0)
				{
					if (vector.Distance(pos, zone.m_position) < zone.m_radius && pos[1] > landPos)
					{
						currentZone = zone;
					}
				}
				else
				{
					zone2d = zone.m_position;
					zone2d[1] = 0;

					if (vector.Distance(pos2d, zone2d) < zone.m_radius && pos[1] >= zone.m_position[1] && pos[1] < zone.m_position[1] + zone.m_height)
					{
						currentZone = zone;
					}
				}
			}
		}
		
		if (currentZone == null)
		{
			if (m_zone != null && m_zone.m_id != pluginZones.m_config.m_defaultZone.m_id && m_zone.m_leaveTime > 0)
			{
				if (m_zoneLeaveTimer < m_zone.m_leaveTime)
				{
					m_zoneLeaveTimer = m_zoneLeaveTimer + 1.0;
					return;
				}
			}
			
			currentZone = pluginZones.m_config.m_defaultZone;
			m_zoneLeaveTimer = 0;
		}
		
		if (m_zone == null || m_zone.m_id != currentZone.m_id)
		{
			if (m_zone != null && m_zone.m_godMode == 1)
			{
				SetAllowDamage(true);
			}
			
			if (currentZone.m_godMode == 1 && !m_isPveIntruder)
			{
				SetAllowDamage(false);
			}
			
			m_zone = currentZone;
			m_zoneLeaveTimer = 0;
			GetSyberiaRPC().SendToClient(SyberiaRPC.SYBRPC_CURRENT_ZONE_SYNC, GetIdentity(), new Param1<ref ZoneDefinition>(currentZone));
			SetSynchDirty();
		}
	}
	
	private void OnTickZoneEffect()
	{
		if (m_zone == null)
		{
			return;
		}
		
		int waterDrain;
		int energyDrain;
		
		if (m_zoneToxicEffect > 0)
		{
			if (m_zoneToxicEffect < 10)
			{
				if (m_zoneToxicEffect % 2 == 0)
				{
					GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
				}
			}
			else
			{			
				if (m_zoneToxicEffect % 10 == 0)
				{
					SymptomBase symptom1 = GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);				
					if( symptom1 )
					{
						symptom1.SetDuration(5);
						
						waterDrain = GetSyberiaConfig().m_stomatchpoisonWaterDrainFromVomit[1];
						energyDrain = GetSyberiaConfig().m_stomatchpoisonEnergyDrainFromVomit[1];
		
						if (GetStatWater().Get() > waterDrain)
							GetStatWater().Add(-1 * waterDrain);
						
						if (GetStatEnergy().Get() > energyDrain)
							GetStatEnergy().Add(-1 * energyDrain);
					}
				}
				
				DecreaseHealth("", "Health", 1);
				SetSynchDirty();
			}
		}
		
		bool filterProtection = false;
		ItemBase filter = GetGasMaskFilter();
		if (filter && filter.GetQuantity() > 0)
		{
			filterProtection = true;
			if (m_zone.m_gas.Length() > 0)
			{
				filter.AddQuantity(GetSyberiaConfig().m_gasMaskFilterDegradationInToxicZone);				
			}
			else if (m_zone.m_radiation > 0)
			{
				filter.AddQuantity(GetSyberiaConfig().m_gasMaskFilterDegradationInRadZone);	
			}
			else
			{
				filter.AddQuantity(GetSyberiaConfig().m_gasMaskFilterDegradationDefault);	
			}
		}
		
		if (m_zone.m_gas.Length() > 0 && !filterProtection)
		{
			m_zoneToxicEffect = m_zoneToxicEffect + 1;
		}
		else if (m_zoneToxicEffect > 0)
		{
			m_zoneToxicEffect = m_zoneToxicEffect - 1;
		}
		
		if (m_zone.m_radiation > 0)
		{
			float radIncrement = (1.0 - GetRadiationProtection()) * m_zone.m_radiation;
			if (radIncrement > 0)
			{
				AddRadiationDose(radIncrement);
			}
		}

		if (GetRadiationDose() > 0)
		{
			if (m_radioprotectionLevel >= 0 && m_radioprotectionLevel <= 3) {
				AddRadiationDose(GetSyberiaConfig().m_radiationDoseDecrementPerSec[m_radioprotectionLevel]);
			}
		}
		
		if (m_radiationSickness > 0)
		{
			DecreaseHealth("", "Health", GetSyberiaConfig().m_radiationHealthDamage[m_radiationSickness - 1]);
		}
		
		if (m_radiationSickness >= 2 && Math.RandomFloat01() < 0.05)
		{
			// Vomit
			SymptomBase symptom2 = GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);				
			if( symptom2 )
			{
				symptom2.SetDuration(3);
				
				waterDrain = GetSyberiaConfig().m_stomatchpoisonWaterDrainFromVomit[2];
				energyDrain = GetSyberiaConfig().m_stomatchpoisonEnergyDrainFromVomit[2];

				if (GetStatWater().Get() > waterDrain)
					GetStatWater().Add(-1 * waterDrain);
				
				if (GetStatEnergy().Get() > energyDrain)
					GetStatEnergy().Add(-1 * energyDrain);
			}
		}
		
		if (m_radiationSickness == 3)
		{
			if (Math.RandomFloat01() < 0.1)
			{
				DecreaseHealth("", "Shock", 20);
			}
			
			if (Math.RandomFloat01() < 0.05 && m_BleedingManagerServer.GetBleedingSourcesCount() == 0)
			{
				GetBleedingManagerServer().AttemptAddBleedingSource(0);
			}
		}
	}
	
	private void OnTickExperience()
	{
		ItemBase itemInHands = GetItemInHands();
		if (itemInHands && itemInHands.IsHeavyBehaviour() && CanDropEntity(itemInHands) && GetPerkBoolValue(SyberiaPerkType.SYBPERK_STRENGTH_HEAVY_ITEMS) == false)
		{
			GetInventory().DropEntity(InventoryMode.SERVER, this, itemInHands);
			GetSyberiaRPC().SendToClient(SyberiaRPC.SYBRPC_SCREEN_MESSAGE, GetIdentity(), new Param1<string>("#syb_skill_overweight_item #syb_perk_name_" + SyberiaPerkType.SYBPERK_STRENGTH_HEAVY_ITEMS));
            SyberiaSoundEmitter.Spawn("JimWow" + Math.RandomIntInclusive(1, 2) + "_SoundEmitter", GetPosition());
		}
		
		if (!IsSicknesOrInjured())
		{
			float moveDist = vector.Distance(m_skillsLastPos, GetPosition());
			if (m_MovementState.m_iMovement == DayZPlayerConstants.MOVEMENTIDX_SPRINT)
			{
				m_sprintingTime = m_sprintingTime + 1;
				if (m_sprintingTime > GetSyberiaConfig().m_skillsExpAthleticsSprintTime && moveDist > 10)
				{
					m_sprintingTime = 0;
					m_skillsLastPos = GetPosition();
					AddExperience(SyberiaSkillType.SYBSKILL_ATHLETICS, GetSyberiaConfig().m_skillsExpAthleticsSprintIncrement);
				}
			}
			else if (m_MovementState.m_iMovement == DayZPlayerConstants.MOVEMENTIDX_RUN && moveDist > 5)
			{
				m_jogingTime = m_jogingTime + 1;
				if (m_jogingTime > GetSyberiaConfig().m_skillsExpAthleticsJogTime)
				{
					m_jogingTime = 0;
					m_skillsLastPos = GetPosition();
					AddExperience(SyberiaSkillType.SYBSKILL_ATHLETICS, GetSyberiaConfig().m_skillsExpAthleticsJogIncrement);
				}
			}
		}
	}
	
	private void OnTickStethoscope()
	{
		Stethoscope itemStatoschope = Stethoscope.Cast(GetItemOnSlot("Eyewear"));
		if (!itemStatoschope)
			return;
		
		ItemBase itemInHands = GetItemInHands();
		if (!itemInHands)
			return;
		
		GetInventory().DropEntity(InventoryMode.SERVER, this, itemStatoschope);
		GetSyberiaRPC().SendToClient(SyberiaRPC.SYBRPC_SCREEN_MESSAGE, GetIdentity(), new Param1<string>("#syb_stethoscope_drop"));
	}
	
	private void OnTickSkills()
	{		
		if (m_charProfile && m_charProfile.m_skills && m_charProfile.m_skills.m_dirty)
		{
			m_charProfile.m_skills.m_dirty = false;			
			GetSyberiaRPC().SendToClient(SyberiaRPC.SYBRPC_SKILLS_UPDATE, GetIdentity(), new Param1<ref SkillsContainer>(m_charProfile.m_skills));
			m_skillsSaveDirty = true;
		}
		
		m_skillsSaveInterval = m_skillsSaveInterval + 1;
		if (m_skillsSaveDirty && m_skillsSaveInterval > 60)
		{
			m_skillsSaveDirty = false;
			m_skillsSaveInterval = 0;
			GetSyberiaCharacters().Save( GetIdentity() );
		}
	}
	
	private void OnTickUnconsition()
	{
		if ( GetModifiersManager().IsModifierActive(eModifiers.MDF_UNCONSCIOUSNESS ) )
		{
			m_ShockHandler.SetMultiplier( GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_UNCUNSION_TIME, 1, 1) );
		}
		else
		{
			m_ShockHandler.SetMultiplier( GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_UNCUNSION_CHANCE, 1, 1) );
		}
	}
	
	private void OnTickSleeping()
	{
		int sleepingDiff = 0;		
		sleepingDiff = sleepingDiff - GetSyberiaConfig().m_sleepingDecPerSec;
		
		if (m_radiationSickness > 0)
		{
			sleepingDiff = sleepingDiff - GetSyberiaConfig().m_radiationSleepingDec;
		}
		
		if (m_sleepingBoostTimer > 0)
		{
			m_sleepingBoostTimer = m_sleepingBoostTimer - 1;
			sleepingDiff = sleepingDiff + m_sleepingBoostValue;
		}

		SyberiaSleepingLevel sleepingLevel = SyberiaSleepingLevel.SYBSL_NONE;		
		if (GetEmoteManager() && GetEmoteManager().IsPlayerSleeping())
		{
			float heatValue = GetStatHeatComfort().Get();
			if (IsSicknesOrInjured())
			{
				sleepingLevel = SyberiaSleepingLevel.SYBSL_SICK;
			}
			else if (m_sleepingBoostTimer > 0)
			{
				sleepingLevel = SyberiaSleepingLevel.SYBSL_ENERGED;
			}
			else if (heatValue < PlayerConstants.THRESHOLD_HEAT_COMFORT_MINUS_WARNING)
			{
				sleepingLevel = SyberiaSleepingLevel.SYBSL_COLD;
			}
			else if (heatValue > PlayerConstants.THRESHOLD_HEAT_COMFORT_PLUS_CRITICAL)
			{
				sleepingLevel = SyberiaSleepingLevel.SYBSL_HOT;
			}
			else if (m_HasHeatBuffer)
			{
				sleepingLevel = SyberiaSleepingLevel.SYBSL_PERFECT;
				sleepingDiff = sleepingDiff + (int)(GetSyberiaConfig().m_sleepingIncPerSleepingLvl2Sec * GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_SLEEPING_TIME, 1, 1));
			}
			else
			{
				sleepingLevel = SyberiaSleepingLevel.SYBSL_COMFORT;
				sleepingDiff = sleepingDiff + (int)(GetSyberiaConfig().m_sleepingIncPerSleepingLvl1Sec * GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_SLEEPING_TIME, 1, 1));
			}
		}
		
		int sleepingLvlInt = (int)sleepingLevel;
		if (sleepingLvlInt != m_sleepingLevel)
		{
			m_sleepingLevel = sleepingLvlInt;
			SetSynchDirty();
		}
		
		if (sleepingLvlInt > 0)
		{
			m_sleepingSoundTimer = m_sleepingSoundTimer + 1;
			if (m_sleepingSoundTimer >= 5)
			{
				m_sleepingSoundTimer = 0;
				if (IsMale()) SyberiaSoundEmitter.Spawn("SleepingMale_SoundEmitter", GetPosition());
				else SyberiaSoundEmitter.Spawn("SleepingFemale_SoundEmitter", GetPosition());
			}
			
			float maxHealth = GetMaxHealth("GlobalHealth","Health");
			AddHealth("GlobalHealth", "Health", maxHealth * GetSyberiaConfig().m_sleepingHealPerSec01);						
			if (m_influenzaLevel <= 1 && GetPerkBoolValue(SyberiaPerkType.SYBPERK_IMMUNITY_INFLUENZA_FIREPLACE_HEAL) && Math.RandomFloat01() < GetSyberiaConfig().m_sleepingHealInfluenzaChance)
			{
				m_influenzaLevel = 0;
				m_influenzaTimer = 0;
				SetSynchDirty();
			}
		}
		else
		{
			m_sleepingSoundTimer = -10;
		}
		
		m_lastSleepingValue = m_sleepingValue;
		m_sleepingValue = m_sleepingValue + sleepingDiff;
		
		if (m_sleepingValue <= 0) 
		{
			if (GetSyberiaConfig().m_sleepingUnconsionEnabled)
			{
				m_UnconsciousEndTime = -60;
				SetHealth("","Shock",0);
				SetSleepingBoost(GetSyberiaConfig().m_sleepingIncPerUnconsionBoostTime, GetSyberiaConfig().m_sleepingIncPerUnconsionBoostValue);
			}
			
			m_sleepingValue = 0;
		}
		
		if (m_sleepingValue > GetSyberiaConfig().m_sleepingMaxValue)
		{
			m_sleepingValue = GetSyberiaConfig().m_sleepingMaxValue;
		}
				
		SetSynchDirty();
	}
	
	private void OnTickSickCheck()
	{
		float currHeatComf = GetStatHeatComfort().Get();
		if (currHeatComf < -0.5)
		{
			if (Math.RandomFloat01() < GetSyberiaConfig().m_influenzaApplyOnColdCritChance)
			{
				AddInfluenza();
			}
		}
		else if (currHeatComf < -0.9)
		{
			if (Math.RandomFloat01() < GetSyberiaConfig().m_influenzaApplyOnColdWarnChance)
			{
				AddInfluenza();
			}
		}
	}
	
	void SetStomatchPoison(int level, float time)
	{
		if (level > m_stomatchpoisonLevel)
		{
			m_stomatchpoisonLevel = Math.Clamp(level, 0, 3);
			SetSynchDirty();
		}
		
		if (m_stomatchpoisonLevel > 0)
		{
			float max = GetSyberiaConfig().m_stomatchpoisonDefaultTimes[m_stomatchpoisonLevel - 1];
			m_stomatchpoisonTimer = Math.Clamp(m_stomatchpoisonTimer + time, 0, max);
			if (m_stomatchpoisonTimer < 60)
			{
				m_stomatchpoisonTimer = 60; 
			}
		}
	}
	
	private void OnTickStomatchpoison()
	{
		int symptomDuration = 0;
		if (m_stomatchpoisonLevel == 1)
		{
			if (m_stomatchhealLevel < 1 && Math.RandomFloat01() < GetSyberiaConfig().m_stomatchpoisonVomitChance[0])
			{
				symptomDuration = Math.RandomIntInclusive( 5, 10 );
			}
		}
		if (m_stomatchpoisonLevel == 2)
		{
			if (m_stomatchhealLevel < 2 && Math.RandomFloat01() < GetSyberiaConfig().m_stomatchpoisonVomitChance[1])
			{
				symptomDuration = Math.RandomIntInclusive( 2, 8 );
			}
		}
		if (m_stomatchpoisonLevel == 3)
		{
			if (m_stomatchhealLevel < 3 && Math.RandomFloat01() < GetSyberiaConfig().m_stomatchpoisonVomitChance[2])
			{
				symptomDuration = Math.RandomIntInclusive( 1, 4 );
			}
		}
				
		m_lastStomatchpoisonHeal = m_lastStomatchpoisonHeal + 1;
		if (m_stomatchpoisonLevel > 0 && m_stomatchpoisonLevel <= 3)
		{
			if (symptomDuration > 0)
			{
				SymptomBase symptom = GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);				
				if( symptom )
				{
					symptom.SetDuration(symptomDuration);
					
					int waterDrain = GetSyberiaConfig().m_stomatchpoisonWaterDrainFromVomit[m_stomatchpoisonLevel - 1];
					int energyDrain = GetSyberiaConfig().m_stomatchpoisonEnergyDrainFromVomit[m_stomatchpoisonLevel - 1];
	
					if (GetStatWater().Get() > waterDrain)
						GetStatWater().Add(-1 * waterDrain);
					
					if (GetStatEnergy().Get() > energyDrain)
						GetStatEnergy().Add(-1 * energyDrain);
				}
			}
			
			m_stomatchpoisonTimer = m_stomatchpoisonTimer - GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_STOMATCHPOISON_TIME, 1, 1);
			if (m_stomatchpoisonTimer < 0)
			{
				m_stomatchpoisonLevel = m_stomatchpoisonLevel - 1;
				if (m_stomatchpoisonLevel > 0 && m_stomatchpoisonLevel <= 3)
				{
					m_stomatchpoisonTimer = GetSyberiaConfig().m_stomatchpoisonDefaultTimes[m_stomatchpoisonLevel - 1];
				}
				else
				{
					if (m_lastStomatchpoisonHeal > 600)
					{
						AddExperience(SyberiaSkillType.SYBSKILL_IMMUNITY, GetSyberiaConfig().m_skillsExpImmunityStomatch);
					}
					
					m_stomatchpoisonTimer = 0;
					m_lastStomatchpoisonHeal = 0;
				}
				SetSynchDirty();
			}
		}
	}
	
	private void OnTickMindState()
	{
		m_mindStateLast = m_mindStateValue;
		if (m_mindDegradationTime > 0)
		{
			m_mindDegradationTime = m_mindDegradationTime - GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_MENTAL_TIME, 1, 1);
			m_mindStateValue = m_mindStateValue - m_mindDegradationForce;
		}
		else 
		{
			m_mindDegradationForce = 0;
			m_mindDegradationTime = 0;
			m_mindStateValue = m_mindStateValue + (GetSyberiaConfig().m_mindstateHealPerSec * GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_MENTAL_TIME, 1, 1));
		}
		
		if (m_antidepresantLevel > 0 && m_antidepresantLevel <= 3)
		{
			m_mindStateValue = m_mindStateValue + GetSyberiaConfig().m_antidepresantMindInc[m_antidepresantLevel - 1];
		}
		
		if (m_zone != null)
		{
			if (m_zone.m_psi > 0)
			{
				float perkMod = 1 - GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_MENTAL_TIME, 0, 0);
				m_mindStateValue = m_mindStateValue - (m_zone.m_psi * perkMod);
			}
		}
				
		m_mindStateValue = Math.Clamp(m_mindStateValue, 0, GetSyberiaConfig().m_mindstateMaxValue);
		
		if (m_mindStateValue < GetSyberiaConfig().m_mindstateLevel5)
		{
			float maxHealth = GetMaxHealth("GlobalHealth","Health");
			DecreaseHealth("", "Health", maxHealth / GetSyberiaConfig().m_mindstateEmptyDeadtimeSec);
		}
		if (m_mindStateValue < GetSyberiaConfig().m_mindstateLevel3)
		{
			float laughtChange = 1 - (m_mindStateValue / GetSyberiaConfig().m_mindstateLevel3);
			if( Math.RandomFloat01() < laughtChange * 0.1 )
			{
				GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_LAUGHTER);
			}
		}
		
		if (m_mindStateLast != m_mindStateValue)
		{
			SetSynchDirty();
		}
	}
	
	void AddMindDegradation(float force, float time)
	{
		if (m_mindDegradationForce < force)
		{
			m_mindDegradationForce = force;
		}
		
		m_mindDegradationTime = m_mindDegradationTime + time;
	}
	
	void SetSleepingBoost(float time, int value)
	{
		m_sleepingBoostTimer = time;
		m_sleepingBoostValue = value;
		SetSynchDirty();
	}
	
	void AddSleepingBoost(float time, int value)
	{
		if (value == m_sleepingBoostValue)
		{
			m_sleepingBoostTimer = m_sleepingBoostTimer + time;
			SetSynchDirty();
		}
		else
		{
			SetSleepingBoost(time, value);
		}
	}
	
	void AddInfluenza()
	{
		if (m_antibioticsLevel > 0) return;
		
		if (m_influenzaLevel == 0 && m_influenzaTimer == 0)
		{
			m_influenzaTimer = GetSyberiaConfig().m_influenzaIncubatePeriodsSec[0];
		}
	}
	
	override bool Consume(ItemBase source, float amount, EConsumeType consume_type )
	{
		bool hasBrainAgents = false;
		if (source)
		{
			if (source.ContainsAgent(eAgents.BRAIN))
			{
				AddMindDegradation(1, amount);
				source.RemoveAgent(eAgents.BRAIN);
				hasBrainAgents = true;
			}
			else if (source.IsInherited(HumanSteakMeat))
			{
				AddMindDegradation(1, amount);
			}
			
			Edible_Base edibleBaseSource = Edible_Base.Cast(source);
			if (edibleBaseSource)
			{
				if (source.IsMeat())
				{
					if (edibleBaseSource.IsFoodRaw()) SetStomatchPoison(GetSyberiaConfig().m_stomatchpoisonRawMeat[0], GetSyberiaConfig().m_stomatchpoisonRawMeat[1] * amount);
					if (edibleBaseSource.IsFoodBurned()) SetStomatchPoison(GetSyberiaConfig().m_stomatchpoisonBurnedMeat[0], GetSyberiaConfig().m_stomatchpoisonBurnedMeat[1] * amount);
					if (edibleBaseSource.IsFoodRotten()) SetStomatchPoison(GetSyberiaConfig().m_stomatchpoisonRottenMeat[0], GetSyberiaConfig().m_stomatchpoisonRottenMeat[1] * amount);
				}
				else
				{
					if (edibleBaseSource.IsFoodRotten()) SetStomatchPoison(GetSyberiaConfig().m_stomatchpoisonRottenFood[0], GetSyberiaConfig().m_stomatchpoisonRottenFood[1] * amount);					
					if (edibleBaseSource.IsFoodBurned()) SetStomatchPoison(GetSyberiaConfig().m_stomatchpoisonBurnedFood[0], GetSyberiaConfig().m_stomatchpoisonBurnedFood[1] * amount);
				}
			}
			
			if (source.ContainsAgent(eAgents.SALMONELLA) || source.ContainsAgent(eAgents.CHOLERA) || source.ContainsAgent(eAgents.FOOD_POISON))
			{
				SetStomatchPoison(GetSyberiaConfig().m_stomatchpoisonInfection[0], GetSyberiaConfig().m_stomatchpoisonInfection[1] * amount);
			}
			
			if (source.IsTemperatureVisible())
			{
				float temperature = source.GetTemperature();
				if (temperature > 40)
				{
					temperature = (Math.Clamp(temperature, 40.0, 80.0) - 40.0) / 40.0;
					GetStatHeatBuffer().Add(temperature * amount * GetSyberiaConfig().m_temperatureHighConsumeItemsMod);
				}
				else if (temperature < 20)
				{
					temperature = (20.0 - Math.Clamp(temperature, -20.0, 20.0)) / 40.0;
					GetStatHeatBuffer().Add(temperature * amount * GetSyberiaConfig().m_temperatureLowConsumeItemsMod);
				}
			}
		}
		
		if (HasDirtyHands())
		{
			SetStomatchPoison(GetSyberiaConfig().m_stomatchpoisonDirtyHands[0], GetSyberiaConfig().m_stomatchpoisonDirtyHands[1] * amount);
		}
		
		if (consume_type == EConsumeType.ENVIRO_POND)
		{
			GetStatHeatBuffer().Add(temperature * amount * GetSyberiaConfig().m_temperatureDrinkPondPenalty);
			
			if (Math.RandomFloat01() < GetSyberiaConfig().m_stomatchpoisonChanceDrinkPond)
			{
				SetStomatchPoison(GetSyberiaConfig().m_stomatchpoisonDrinkPond[0], GetSyberiaConfig().m_stomatchpoisonDrinkPond[1] * amount);
			}
		}
		
		if (consume_type == EConsumeType.ENVIRO_WELL)
		{
			GetStatHeatBuffer().Add(temperature * amount * GetSyberiaConfig().m_temperatureDrinkWellPenalty);
			
			if (Math.RandomFloat01() < GetSyberiaConfig().m_stomatchpoisonChanceDrinkWell)
			{
				SetStomatchPoison(GetSyberiaConfig().m_stomatchpoisonDrinkWell[0], GetSyberiaConfig().m_stomatchpoisonDrinkWell[1] * amount);
			}
		}
	
		bool result = super.Consume(source, amount, consume_type);
				
		if (result)
		{
			SodaCan_EnergyDrink edible_item = SodaCan_EnergyDrink.Cast(source);
			if (edible_item)
			{
				AddSleepingBoost(amount, 10);
			}
		}
		
		if (hasBrainAgents)
		{
			source.InsertAgent(eAgents.BRAIN);
		}
		
		ItemBase gloves = GetItemOnSlot("Gloves");
		if (gloves)
		{
			gloves.SetCleanness(0);
		}
		else if ( GetModifiersManager().IsModifierActive(eModifiers.MDF_DISINFECTION))
		{
			GetModifiersManager().DeactivateModifier( eModifiers.MDF_DISINFECTION );
		}
		
		return result;
	}
	
	private float ProcessOverdosedPostinc(float time, float overdoseInc)
	{
		if (time > 3000) return overdoseInc * 5.0;
		if (time > 1000) return overdoseInc * 3.0;
		if (time > 500) return overdoseInc * 2.5;
		if (time > 300) return overdoseInc * 2.0;
		if (time > 100) return overdoseInc * 1.5;
		return overdoseInc;
	}
	
	// medPainkillerLevel, medPainkillerTimeSec
	// medStomatchhealLevel, medStomatchhealTimeSec
	// medAntibioticLevel, medAntibioticsTimeSec, medAntibioticsStrength
	// medHemologicShock
	// medRemoveSepsis
	// medRemoveZVirus
	// medBloodStop
	// medConcussionHeal
	// medBloodHemostatic, medBloodHemostaticTimeSec
	// medBloodHematopoiesis, medBloodHematopoiesisTimeSec
	// medHematomaHeal, medHematomaHealTimeSec
	// medAdrenalinLevel, medAdrenalinTimeSec
	void ApplyAdvMedicineItem(string classname, float amount)
	{
		float overdosedIncrement = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " overdosedIncrement" );
			
		int medPainkillerLevel = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medPainkillerLevel" );
		if (medPainkillerLevel > 0)
		{
			overdosedIncrement = ProcessOverdosedPostinc(m_painkillerTime, overdosedIncrement);
			float medPainkillerTimeSec = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " medPainkillerTimeSec" );
			if (medPainkillerLevel >= m_painkillerEffect && medPainkillerTimeSec > 0)
			{				
				m_painkillerEffect = medPainkillerLevel;
				m_painkillerTime = m_painkillerTime + (medPainkillerTimeSec * amount);
			}
		}
		
		int medStomatchhealLevel = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medStomatchhealLevel" );
		if (medStomatchhealLevel > 0)
		{
			overdosedIncrement = ProcessOverdosedPostinc(m_stomatchhealTimer, overdosedIncrement);
			float medStomatchhealTimeSec = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " medStomatchhealTimeSec" );
			if (medStomatchhealLevel >= m_stomatchhealLevel && medStomatchhealTimeSec > 0)
			{
				m_stomatchhealLevel = medStomatchhealLevel;
				m_stomatchhealTimer = m_stomatchhealTimer + (medStomatchhealTimeSec * amount);
			}
		}
		
		int medAntibioticLevel = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medAntibioticLevel" );
		if (medAntibioticLevel > 0)
		{			
			overdosedIncrement = ProcessOverdosedPostinc(m_antibioticsTimer, overdosedIncrement);
			float medAntibioticsTimeSec = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " medAntibioticsTimeSec" );
			float medAntibioticsStrength = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " medAntibioticsStrength" );
			if (medAntibioticLevel >= m_antibioticsLevel && medAntibioticsTimeSec > 0 && medAntibioticsStrength > 0)
			{
				m_antibioticsLevel = medAntibioticLevel;
				m_antibioticsTimer = m_antibioticsTimer + (medAntibioticsTimeSec * amount);
				m_antibioticsStrange = medAntibioticsStrength;
			}			
		}
		
		/*int medHemologicShock = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medHemologicShock" );
		if (medHemologicShock > 0)
		{
			m_hemologicShock = true;
		}*/
		
		int medRemoveSepsis = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medRemoveSepsis" );
		if (medRemoveSepsis > 0)
		{
			m_BleedingManagerServer.SetBloodInfection(false);
		}
		
		int medRemoveZVirus = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medRemoveZVirus" );
		if (medRemoveZVirus > 0)
		{			
			if (medRemoveZVirus <= 1)
			{
				float maxBlood = GetMaxHealth("GlobalHealth","Blood");
				float maxHealth = GetMaxHealth("GlobalHealth","Health");
				DecreaseHealth("", "Blood", maxBlood * GetSyberiaConfig().m_zvirusAntidotBloodDmg01);
				DecreaseHealth("", "Health", maxHealth * GetSyberiaConfig().m_zvirusAntidotHealthDmg01);
			}
			
			if (medRemoveZVirus <= 2)
			{
				m_UnconsciousEndTime = -60;
				SetHealth("","Shock",0);
			}
			
			m_BleedingManagerServer.SetZVirus(false);
		}
		
		int medBloodStop = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medBloodStop" );
		if (medBloodStop > 0)
		{
			m_BleedingManagerServer.ApplyBandage(medBloodStop);
		}
		
		int medConcussionHeal = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medConcussionHeal" );
		if (medConcussionHeal > 0)
		{
			m_BleedingManagerServer.SetConcussionHit(false);
		}
		
		int medBloodHemostatic = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medBloodHemostatic" );
		if (medBloodHemostatic > 0)
		{
			m_bloodHemostaticEffect = true;
			float medBloodHemostaticTimeSec = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " medBloodHemostaticTimeSec" );
			overdosedIncrement = ProcessOverdosedPostinc(m_bloodHemostaticTimer, overdosedIncrement);
			m_bloodHemostaticTimer = m_bloodHemostaticTimer + (medBloodHemostaticTimeSec * amount);
		}
		
		int medBloodHematopoiesis = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medBloodHematopoiesis" );
		if (medBloodHematopoiesis > 0)
		{
			m_hematopoiesisEffect = true;
			float medBloodHematopoiesisTimeSec = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " medBloodHematopoiesisTimeSec" );
			overdosedIncrement = ProcessOverdosedPostinc(m_hematopoiesisTimer, overdosedIncrement);
			m_hematopoiesisTimer = m_hematopoiesisTimer + (medBloodHematopoiesisTimeSec * amount);
		}
		
		int medHematomaHeal = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medHematomaHeal" );
		if (medHematomaHeal > 0)
		{
			m_salveEffect = true;
			float medHematomaHealTimeSec = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " medHematomaHealTimeSec" );
			overdosedIncrement = ProcessOverdosedPostinc(m_salveEffectTimer, overdosedIncrement);
			m_salveEffectTimer = m_salveEffectTimer + (medHematomaHealTimeSec * amount);
		}
		
		int medAdrenalinLevel = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medAdrenalinLevel" );
		if (medAdrenalinLevel > 0)
		{
			overdosedIncrement = ProcessOverdosedPostinc(m_adrenalinEffectTimer, overdosedIncrement);
			if (m_adrenalinEffect <= medAdrenalinLevel)
			{
				m_adrenalinEffect = medAdrenalinLevel;
				float medAdrenalinTimeSec = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " medAdrenalinTimeSec" );
				m_adrenalinEffectTimer = m_adrenalinEffectTimer + (medAdrenalinTimeSec * amount);
			}
			
			GetStaminaHandler().SetStamina( GetStaminaHandler().GetStaminaMax() );
		}
		
		int medRadprotectLevel = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medRadioprotectionLevel" );
		if (medRadprotectLevel > 0)
		{
			overdosedIncrement = ProcessOverdosedPostinc(m_radioprotectionTimer, overdosedIncrement);
			float medRadprotectTimeSec = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " medRadioprotectionTimer" );
			if (medRadprotectLevel >= m_radioprotectionLevel && medRadprotectTimeSec > 0)
			{
				m_radioprotectionLevel = medRadprotectLevel;
				m_radioprotectionTimer = m_radioprotectionTimer + (medRadprotectTimeSec * amount);
			}
		}
		
		int medAntidepLevel = GetGame().ConfigGetInt( "CfgVehicles " + classname + " medAntidepresantLevel" );
		if (medAntidepLevel > 0)
		{
			overdosedIncrement = ProcessOverdosedPostinc(m_antidepresantTimer, overdosedIncrement);
			float medAntidepTimeSec = GetGame().ConfigGetFloat( "CfgVehicles " + classname + " medAntidepresantTimer" );
			if (medAntidepLevel >= m_antidepresantLevel && medAntidepTimeSec > 0)
			{
				m_antidepresantLevel = medAntidepLevel;
				m_antidepresantTimer = m_antidepresantTimer + (medAntidepTimeSec * amount);
			}
		}
		
		m_overdosedValue = m_overdosedValue + overdosedIncrement;		
		SetSynchDirty();
	}
	
	protected void OnTickAdvMedicine_Bloodlose(float deltaTime)
	{		
		while (m_bulletBandage1 + m_bulletBandage2 > m_bulletHits)
		{
			if (m_bulletBandage1 > 0) m_bulletBandage1 = m_bulletBandage1 - 1;
			else if (m_bulletBandage2 > 0) m_bulletBandage2 = m_bulletBandage2 - 1;
			SetSynchDirty();
		}
		
		while (m_knifeBandage1 + m_knifeBandage2 > m_knifeHits)
		{
			if (m_knifeBandage1 > 0) m_knifeBandage1 = m_knifeBandage1 - 1;
			else if (m_knifeBandage2 > 0) m_knifeBandage2 = m_knifeBandage2 - 1;
			SetSynchDirty();
		}
		
		int bh_opened = m_bulletHits - (m_bulletBandage1 + m_bulletBandage2);
		int kh_opened = m_knifeHits - (m_knifeBandage1 + m_knifeBandage2);
		
		float bloodlose = 0;
		bloodlose = bloodlose + (bh_opened * GetSyberiaConfig().m_bleedingBullethitOpenPerSecond);
		bloodlose = bloodlose + (m_bulletBandage1 * GetSyberiaConfig().m_bleedingBullethitCupd1PerSecond);
		bloodlose = bloodlose + (m_bulletBandage2 * GetSyberiaConfig().m_bleedingBullethitCupd2PerSecond);
		bloodlose = bloodlose + (kh_opened * GetSyberiaConfig().m_bleedingKnifehitOpenPerSecond);
		bloodlose = bloodlose + (m_knifeBandage1 * GetSyberiaConfig().m_bleedingKnifehitCupd1PerSecond);
		bloodlose = bloodlose + (m_knifeBandage2 * GetSyberiaConfig().m_bleedingKnifehitCupd2PerSecond);
		bloodlose = bloodlose + (m_visceraHit * GetSyberiaConfig().m_bleedingVisceraBloodlosePerSecond);
		bloodlose = bloodlose + (m_hematomaHits * GetSyberiaConfig().m_bleedingHematomaBloodlosePerSecond);
		if (bloodlose > 0.01)
		{
			if (m_bloodHemostaticEffect)
			{
				bloodlose = bloodlose * GetSyberiaConfig().m_hemostaticEffectModifier;
			}
			DecreaseHealth("", "Blood", bloodlose * deltaTime);
		}
		
		float healthlose = 0;
		healthlose = healthlose + (bh_opened * GetSyberiaConfig().m_bleedingBullethitHealthlosePerSecond);
		healthlose = healthlose + (kh_opened * GetSyberiaConfig().m_bleedingKnifehitHealthlosePerSecond);
		healthlose = healthlose + (m_visceraHit * GetSyberiaConfig().m_bleedingVisceraHealthlosePerSecond);
		healthlose = healthlose + (m_hematomaHits * GetSyberiaConfig().m_bleedingHematomaHealthlosePerSecond);
		if (healthlose > 0.01)
		{
			DecreaseHealth("", "Health", healthlose * deltaTime);
		}
	}
	
	protected void OnTickAdvMedicine_Salve(float deltaTime)
	{
		if (m_salveEffect)
		{
			m_salveEffectTimer = m_salveEffectTimer - deltaTime;
			if (m_salveEffectTimer < 0)
			{
				m_salveEffect = false;
				SetSynchDirty();
			}
		}
		else
		{
			m_salveEffectTimer = 0;
		}
	}
	
	protected void OnTickAdvMedicine_Regen(float deltaTime)
	{
		if (m_hematomaHits > 0)
		{
			float hematomaRegenOffset = deltaTime * GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_HEMATOMA_TIME, 1, 1); 
			if (m_salveEffect)
			{
				hematomaRegenOffset = hematomaRegenOffset * GetSyberiaConfig().m_hematomaRegenTimeBoostOnSalve;
			}
			
			m_hematomaRegenTimer = m_hematomaRegenTimer + hematomaRegenOffset;
			if (m_hematomaRegenTimer > GetSyberiaConfig().m_hematomaRegenTimerSec)
			{
				m_hematomaRegenTimer = 0;
				m_hematomaHits = m_hematomaHits - 1;
				
				AddExperience(SyberiaSkillType.SYBSKILL_IMMUNITY, GetSyberiaConfig().m_skillsExpImmunityHematoma);
			}
		}
		else
		{
			m_hematomaRegenTimer = 0;
		}
		
		if (GetBleedingBits() != 0)
		{
			m_cuthitRegenTimer = m_cuthitRegenTimer + (deltaTime * GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_CUTHIT_TIME, 1, 1));
			if (m_cuthitRegenTimer > GetSyberiaConfig().m_cuthitRegenTimerSec)
			{
				m_cuthitRegenTimer = 0;
				if (m_BleedingManagerServer)
				{
					m_BleedingManagerServer.RemoveMostSignificantBleedingSource();
				}
			}
		}
		else
		{
			m_cuthitRegenTimer = 0;
		}
		
		if (GetSyberiaConfig().m_bleedingBullethitRemoveBandagedTimeSec > 0 && m_bulletHits > 0 && (m_bulletBandage1 + m_bulletBandage2) > 0)
		{
			m_bullethitRegenTimer = m_bullethitRegenTimer + deltaTime;
			if (m_bullethitRegenTimer > GetSyberiaConfig().m_bleedingBullethitRemoveBandagedTimeSec)
			{
				m_bullethitRegenTimer = 0;
				m_BleedingManagerServer.RemoveBulletHit(true);
			}
		}
		else
		{
			m_bullethitRegenTimer = 0;
		}
		
		if (GetSyberiaConfig().m_bleedingKnifehitRemoveBandagedTimeSec > 0 && m_knifeHits > 0 && (m_knifeBandage1 + m_knifeBandage2) > 0)
		{
			m_knifehitRegenTimer = m_knifehitRegenTimer + deltaTime;
			if (m_knifehitRegenTimer > GetSyberiaConfig().m_bleedingKnifehitRemoveBandagedTimeSec)
			{
				m_knifehitRegenTimer = 0;
				m_BleedingManagerServer.RemoveKnifeHit(true);
			}
		}
		else
		{
			m_knifehitRegenTimer = 0;
		}
		
		if (m_concussionHit)
		{
			m_concussionRegenTimer = m_concussionRegenTimer + deltaTime;
			if (m_concussionRegenTimer > GetSyberiaConfig().m_concussionRegenTimeSec)
			{
				m_concussionRegenTimer = 0;
				m_BleedingManagerServer.SetConcussionHit(false);
			}
		}
		else
		{
			m_concussionRegenTimer = 0;
		}
	}
	
	protected void OnTickAdvMedicine_Pain(float deltaTime)
	{
		m_painTimer = Math.Clamp(m_painTimer - deltaTime, 0, GetSyberiaConfig().m_painMaxDurationSec);
		if (m_painLevel > 0 && m_painTimer < 0.1)
		{
			AddExperience(SyberiaSkillType.SYBSKILL_IMMUNITY, GetSyberiaConfig().m_skillsExpImmunityPain * m_painLevel);
			
			m_painLevel = m_painLevel - 1;
			if (m_painLevel == 2) m_painTimer = GetSyberiaConfig().m_painLvl2TimeSec;
			else if (m_painLevel == 1) m_painTimer = GetSyberiaConfig().m_painLvl1TimeSec;
			SetSynchDirty();
		}
		
		if (m_painLevel < 3 && m_visceraHit)
		{
			m_painLevel = 3;
			if (m_painTimer < GetSyberiaConfig().m_painLvl3TimeSec) 
			{
				m_painTimer = GetSyberiaConfig().m_painLvl3TimeSec;
			}
			SetSynchDirty();
		}
		else if (m_painLevel < 2 && (m_knifeHits > 0 || m_bulletHits > 0))
		{
			m_painLevel = 2;
			if (m_painTimer < GetSyberiaConfig().m_painLvl2TimeSec) 
			{
				m_painTimer = GetSyberiaConfig().m_painLvl2TimeSec;
			}
			SetSynchDirty();
		}
		
		if (m_painkillerEffect != 0)
		{
			m_painkillerTime = m_painkillerTime - deltaTime;
			if (m_painkillerTime < 0)
			{
				m_painkillerEffect = 0;
				m_painkillerTime = 0;
				SetSynchDirty();
			}
		}
		
		int currentPainLvl = GetCurrentPainLevel();
		int currentShock = GetHealth("","Shock");
		if (currentPainLvl == 3 && currentShock > 40)
		{
			if (Math.RandomFloat01() <= deltaTime * 0.05)
			{
				DecreaseHealth("", "Shock", 20);
			}
		}
		else if ((m_concussionHit || currentPainLvl == 2) && currentShock > 60)
		{
			if (Math.RandomFloat01() <= deltaTime)
			{
				DecreaseHealth("","Shock",10);
			}
		}
	}
	
	protected void OnTickAdvMedicine_Sepsis(float deltaTime)
	{
		if (m_sepsis > 0)
		{
			m_sepsisTime = m_sepsisTime + (deltaTime * GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_SEPSIS_TIME, 1, 1));
						
			if (m_sepsisTime > GetSyberiaConfig().m_sepsisStage1TimeSec)
			{
				if (m_sepsis == 1)
				{
					m_sepsis = 2;
					SetSynchDirty();
				}
				
				AddToEnvironmentTemperature(GetSyberiaConfig().m_sepsisHighTemperatureValue);
			}
			
			if (m_sepsisTime > GetSyberiaConfig().m_sepsisStage2TimeSec)
			{
				if (m_sepsis == 2)
				{
					m_sepsis = 3;
					SetSynchDirty();
				}
				
				float maxHealth = GetMaxHealth("GlobalHealth","Health");
				DecreaseHealth("GlobalHealth","Health", (maxHealth / GetSyberiaConfig().m_sepsisDeathTimeSec) * deltaTime);
			}
		}
		else
		{
			m_sepsisTime = 0;
		}
	}
	
	protected void OnTickAdvMedicine_ZVirus(float deltaTime)
	{
		if (m_zombieVirus)
		{
			m_zvirusTimer = m_zvirusTimer + (deltaTime * GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_ZVIRUS_TIME, 1, 1));
			
			if (m_zvirusTimer > GetSyberiaConfig().m_zvirusStage1TimeSec)
			{
				if (m_zombieVirus == 1) 
				{
					m_zombieVirus = 2;
					SetSynchDirty();
				}
				
				AddHealth("GlobalHealth","Blood", GetSyberiaConfig().m_zvirusBloodRegenPerSec * deltaTime);
			}
			
			if (m_zvirusTimer > GetSyberiaConfig().m_zvirusStage2TimeSec)
			{
				if (m_zombieVirus == 2)
				{
					m_zombieVirus = 3;
					SetSynchDirty();
				}
				
				float maxHealth = GetMaxHealth("GlobalHealth","Health");
				DecreaseHealth("GlobalHealth","Health", (maxHealth / GetSyberiaConfig().m_zvirusDeathTimeSec) * deltaTime);
			}
		}
		else
		{
			m_zvirusTimer = 0;
		}
	}
	
	protected void OnTickAdvMedicine_Stomatchheal(float deltaTime)
	{
		if (m_stomatchhealLevel == 0)
			return;

		if (m_stomatchpoisonLevel > 0)
		{
			m_stomatchpoisonTimer = m_stomatchpoisonTimer - (deltaTime * m_stomatchhealLevel * GetSyberiaConfig().m_stomatchhealModifier);
		}
		
		m_stomatchhealTimer = Math.Clamp(m_stomatchhealTimer - deltaTime, 0, 999999);
		if (m_stomatchhealTimer < 0.1)
		{
			m_stomatchhealLevel = 0;
			m_stomatchhealTimer = 0;			
			SetSynchDirty();
		}		
	}
	
	protected void OnTickAdvMedicine_Antibiotics(float deltaTime)
	{
		if (m_antibioticsLevel > 0)
		{
			if (m_antibioticsTimer > 0)
			{
				m_antibioticsTimer = m_antibioticsTimer - deltaTime;
				if (m_influenzaLevel > 0 && m_influenzaLevel <= m_antibioticsLevel)
				{
					float antibioticsMdfrLvl = Math.Clamp((m_antibioticsLevel - m_influenzaLevel) + 1, 1, 4);
					float antibioticsMdfrMod = m_antibioticsStrange * antibioticsMdfrLvl * deltaTime * GetSyberiaConfig().m_antibioticsGlobalEffectivityModifier;
					if (Math.RandomFloat01() <= antibioticsMdfrMod)
					{
						m_influenzaLevel = m_influenzaLevel - 1;
						if (m_influenzaLevel > 0 && m_influenzaLevel < 3)
						{
							m_influenzaTimer = GetSyberiaConfig().m_influenzaIncubatePeriodsSec[m_influenzaLevel];
						}
						else
						{
							m_influenzaTimer = 0;
							AddExperience(SyberiaSkillType.SYBSKILL_IMMUNITY, GetSyberiaConfig().m_skillsExpImmunityInfluenza);
						}
						
						SetSynchDirty();
					}
				}
			}
			else
			{
				m_antibioticsTimer = 0;
				m_antibioticsLevel = 0;
				m_antibioticsStrange = 0;
				SetSynchDirty();
			}
		}
		
		AntibioticsAttack( deltaTime );
	}
	
	protected void OnTickAdvMedicine_Influenza(float deltaTime)
	{
		if (m_influenzaTimer > 0)
		{
			m_influenzaTimer = m_influenzaTimer - (deltaTime * GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_INFLUENZA_TIME, 1, 1));
			if (m_influenzaTimer <= 0)
			{
				if (m_influenzaLevel > 0 && m_antibioticsLevel >= m_influenzaLevel)
				{
					m_influenzaTimer = GetSyberiaConfig().m_influenzaIncubatePeriodsSec[m_influenzaLevel];
				}
				else if (m_influenzaLevel < 3)
				{
					m_influenzaLevel = m_influenzaLevel + 1;
					m_influenzaTimer = GetSyberiaConfig().m_influenzaIncubatePeriodsSec[m_influenzaLevel];
					SetSynchDirty();
				}
				else
				{
					m_influenzaTimer = 0;
				}
			}
		}
		
		if (m_influenzaLevel > 0 && m_influenzaLevel <= 3)
		{
			int influenzaLevelIndex = m_influenzaLevel - 1;	
			if (GetSyberiaConfig().m_influenzaTemperatureLevels[influenzaLevelIndex] > 0)
			{
				AddToEnvironmentTemperature(GetSyberiaConfig().m_influenzaTemperatureLevels[influenzaLevelIndex]);
			}
			
			if ( Math.RandomFloat01() < GetSyberiaConfig().m_influenzaSympthomChance[influenzaLevelIndex] * deltaTime )
			{
				if (influenzaLevelIndex == 0)
				{
					GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_SNEEZE);
				}
				else
				{
					GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
				}
			}
			
			float healthloseTime = GetSyberiaConfig().m_influenzaDeathTime[influenzaLevelIndex];
			if (healthloseTime > 0)
			{
				float maxHealth = GetMaxHealth("GlobalHealth","Health");
				DecreaseHealth("GlobalHealth","Health", (maxHealth / healthloseTime) * deltaTime);
			}
		}
	}
	
	protected void OnTickAdvMedicine_Overdose(float deltaTime)
	{
		if (m_overdosedValue > 2)
		{
			float curShock = GetHealth("", "Shock");
			if (curShock > 50)
			{
				if (Math.RandomFloat01() < GetSyberiaConfig().m_overdoseUnconChangePerSec * deltaTime)
				{
					m_UnconsciousEndTime = -60;
					SetHealth("","Shock",0);
				}
			}
		}
		
		if (m_overdosedValue > 3)
		{
			float maxHealth = GetMaxHealth("GlobalHealth","Health");
			DecreaseHealth("GlobalHealth","Health", (maxHealth / 100) * (m_overdosedValue - 3) * deltaTime);
		}
		
        if (m_overdosedValue > 0)
        {
			int lastOverdoseInt = (int)m_overdosedValue;
            m_overdosedValue = m_overdosedValue - (GetSyberiaConfig().m_overdoseDecrementPerSec * GetPerkFloatValue(SyberiaPerkType.SYBPERK_IMMUNITY_OVERDOSE_STRONG, 1, 1) * deltaTime);
			int newOverdoseInt = (int)m_overdosedValue;
			if (lastOverdoseInt != newOverdoseInt)
			{
				SetSynchDirty();
			}
			
			if (lastOverdoseInt > 0 && newOverdoseInt == 0)
			{
				AddExperience(SyberiaSkillType.SYBSKILL_IMMUNITY, GetSyberiaConfig().m_skillsExpImmunityOverdose);
			}
        }
	}
	
	/*protected void OnTickAdvMedicine_HemorlogicShock(float deltaTime)
	{
		if (m_hemologicShock)
		{
			m_UnconsciousEndTime = -60;
			SetHealth("","Shock",0);
			
			float maxHealth = GetMaxHealth("GlobalHealth","Health");
			DecreaseHealth("GlobalHealth","Health", (maxHealth / HEMOLOGIC_SHOCK_DIETIME_SEC) * deltaTime);
			SetSynchDirty();
		}
	}*/
	
	protected void OnTickAdvMedicine_HemostatickEffect(float deltaTime)
	{
		if (m_bloodHemostaticEffect)
		{
			m_bloodHemostaticTimer = m_bloodHemostaticTimer - deltaTime;
			if (m_bloodHemostaticTimer < 0)
			{
				m_bloodHemostaticEffect = false;
				SetSynchDirty();
			}
		}
	}
	
	protected void OnTickAdvMedicine_HematopoiesisEffect(float deltaTime)
	{
		if (m_hematopoiesisEffect)
		{
			m_hematopoiesisTimer = m_hematopoiesisTimer - deltaTime;
			if (m_hematopoiesisTimer < 0)
			{
				m_hematopoiesisEffect = false;
				SetSynchDirty();
			}
			else
			{
				AddHealth("", "Blood", GetSyberiaConfig().m_hematopoiesisEffectBloodPerSec * deltaTime);
			}
		}
	}
	
	protected void OnTickAdvMedicine_Adrenalin(float deltaTime)
	{
		float staminaDepMod = 1;
		if (m_adrenalinEffect > 0)
		{
			m_adrenalinEffectTimer = m_adrenalinEffectTimer - deltaTime;
			if (m_adrenalinEffectTimer < 0)
			{
				m_adrenalinEffect = 0;
				SetSynchDirty();
			}
			else
			{
				if (m_adrenalinEffect >= 1 && m_adrenalinEffect <= 3)
				{		
					float maxShock = GetMaxHealth("GlobalHealth","Shock");			
					float shockEffectValue = GetSyberiaConfig().m_adrenalinEffectShockUpPerSec[m_adrenalinEffect - 1]; 
					AddHealth("", "Shock", shockEffectValue * maxShock * deltaTime);
					
					staminaDepMod = GetSyberiaConfig().m_adrenalinEffectStaminaDepletionMod[m_adrenalinEffect - 1];
				}
			}
		}
		else
		{
			m_adrenalinEffectTimer = 0;
		}
			
		if (GetStaminaHandler().GetDepletionMultiplier() != staminaDepMod)
		{
			GetStaminaHandler().SetDepletionMultiplier( staminaDepMod );
		}
	}

	protected void OnTickAdvMedicine_Antidepresant(float deltaTime)
	{
		if (m_antidepresantLevel > 0)
		{
			m_antidepresantTimer = m_antidepresantTimer - deltaTime;
			if (m_antidepresantTimer < 0)
			{
				m_antidepresantLevel = 0;
				SetSynchDirty();
			}
		}
		else
		{
			m_antidepresantTimer = 0;
		}
	}
		
	protected void OnTickAdvMedicine_Radprotector(float deltaTime)
	{
		if (m_radioprotectionLevel > 0)
		{
			m_radioprotectionTimer = m_radioprotectionTimer - deltaTime;
			if (m_radioprotectionTimer < 0)
			{
				m_radioprotectionLevel = 0;
				SetSynchDirty();
			}
		}
		else
		{
			m_radioprotectionTimer = 0;
		}
	}
	
	bool HasDirtyHands()
	{
		ItemBase gloves = GetItemOnSlot("Gloves");
		if (!gloves && HasBloodyHands())
		{
			return true;
		}
		
		return false;
	}
	
	void AddExperience(int id, float value)
	{
		if (IsAlive() && m_charProfile && m_charProfile.m_skills)
		{
			m_charProfile.m_skills.AddExpirience(id, value);
		}
	}
	
	override int GetSkillValue(int skillId)
	{
		if (IsAlive() && m_charProfile && m_charProfile.m_skills)
		{
			int result = m_charProfile.m_skills.GetSkillValueInt(skillId);
			if (result != -1)
			{
				return result;
			}
		}
		
		return 0;
	}
	
	override int GetPerkIntValue(int perkId, int defaultValue = 0)
	{
		if (IsAlive() && m_charProfile && m_charProfile.m_skills)
		{
			int result = m_charProfile.m_skills.GetPerkValue(perkId);
			if (result != -1)
			{
				return result;
			}
		}
		
		return defaultValue;
	}
	
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		
		PlayerBase otherPlayer = PlayerBase.Cast(killer);
		if (otherPlayer && !this.m_isPveIntruder)
		{
			if (otherPlayer.IsInversedDammageEnabled() || this.IsInversedDammageEnabled())
			{
				otherPlayer.SetAllowDamage(true);
				otherPlayer.SetHealth("", "", 0);
			}
		}
	}
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		bool inverseDammage = false;
		PlayerBase sourcePlayer = PlayerBase.Cast( source.GetHierarchyRootPlayer() );
		if (sourcePlayer)
		{
			if (sourcePlayer.IsInversedDammageEnabled() || this.IsInversedDammageEnabled())
			{
				if (!this.m_isPveIntruder)
				{
					this.AddHealth("", "", damageResult.GetDamage("", ""));
					
					sourcePlayer.SetAllowDamage(true);
					sourcePlayer.DecreaseHealth("", "", damageResult.GetDamage("", ""));
					sourcePlayer.m_isPveIntruder = true;
					sourcePlayer.SetSynchDirty();
					inverseDammage = true;
				}
			}
			else if (damageResult != null && source != null)
			{
				string ammoType = GetGame().ConfigGetTextOut( "CfgAmmo " + ammo + " DamageApplied " + "type" );
				if (ammoType == "Melee")
				{
					float additionalDmg = damageResult.GetDamage(dmgZone, "Health");
					if ( ammo.Contains("_Heavy") )
					{
						additionalDmg = additionalDmg * sourcePlayer.GetPerkFloatValue(SyberiaPerkType.SYBPERK_STRENGTH_HEAVY_ATTACK_STRENGTH, 0, 0);
						
						if (dmgZone == "Head" && sourcePlayer.GetPerkBoolValue(SyberiaPerkType.SYBPERK_STRENGTH_KNOCKOUT_HEAVY_ITEMS))
						{
							SetHealth("", "Shock", 0);
							GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater(KnockoutStateReset, 1000, false);
						}
						
						if (Math.RandomFloat01() < GetSyberiaConfig().m_skillsExpStrengthHeavyAttackChance)
						{
							sourcePlayer.AddExperience(SyberiaSkillType.SYBSKILL_STRENGTH, GetSyberiaConfig().m_skillsExpStrengthHeavyAttackValue);
						}
					}
					else
					{
						additionalDmg = additionalDmg * sourcePlayer.GetPerkFloatValue(SyberiaPerkType.SYBPERK_STRENGTH_FAST_ATTACK_STRENGTH, 0, 0);
						
						if (Math.RandomFloat01() < GetSyberiaConfig().m_skillsExpStrengthLightAttackChance)
						{
							sourcePlayer.AddExperience(SyberiaSkillType.SYBSKILL_STRENGTH, GetSyberiaConfig().m_skillsExpStrengthLightAttackValue);
						}
					}
					
					if (additionalDmg > 0)
					{
						DecreaseHealth("", "Health", additionalDmg);
					}
				}
			}
		}
		
		if (inverseDammage && sourcePlayer)
		{
			sourcePlayer.EEHitBy(damageResult, damageType, this, component, dmgZone, ammo, modelPos, speedCoef);
		}
		else
		{
			super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		}
	}
	
	override void SetBloodyHands( bool show )
	{
		super.SetBloodyHands(show);
		if (show)
		{
			if ( GetModifiersManager().IsModifierActive(eModifiers.MDF_DISINFECTION))
			{
				GetModifiersManager().DeactivateModifier( eModifiers.MDF_DISINFECTION );
			}
		}
	}
	
	void KnockoutStateReset()
	{
		if (!IsAlive()) return;
		SetHealth("", "Shock", 50);
	}
	
	ItemBase GetGasMaskFilter()
	{
		ItemBase itemMask = GetItemOnSlot("Mask");
		if (!itemMask) return null;
		
		return ItemBase.Cast( itemMask.GetInventory().FindAttachmentByName("GasMaskFilter") );
	}
	
	void OnRadiationDoseChanged()
	{
		int newRadLevel = 0;
		if (m_radiationDose > GetSyberiaConfig().m_radiationLevels[2])
		{
			newRadLevel = 3;
		}
		else if (m_radiationDose > GetSyberiaConfig().m_radiationLevels[1])
		{
			newRadLevel = 2;
		}
		else if (m_radiationDose > GetSyberiaConfig().m_radiationLevels[0])
		{
			newRadLevel = 1;
		}
		
		if (newRadLevel != m_radiationSickness)
		{
			m_radiationSickness = newRadLevel;
			SetSynchDirty();
		}
	}
	
	void SetRadiationDose(float dose)
	{
		m_radiationDose = Math.Max(0, dose);
		OnRadiationDoseChanged();
	}
	
	void AddRadiationDose(float dose)
	{
		m_radiationDose = Math.Max(0, m_radiationDose + dose);
		OnRadiationDoseChanged();
	}
	
	float GetRadiationDose()
	{
		return m_radiationDose;
	}
	
	// 0 - no protection
	// 1 - full protection
	float GetRadiationProtection()
	{
		float value = 0;
		float state = 0;
		EntityAI attachment;
		int attCount = GetInventory().AttachmentCount();
		for ( int attIdx = 0; attIdx < attCount; attIdx++ )
		{
			attachment = GetInventory().GetAttachmentFromIndex( attIdx );
			if ( attachment && attachment.IsClothing() )
			{
				state = Math.Clamp(attachment.GetHealth01("", "") * 2, 0, 1);
				value = value + (GetGame().ConfigGetFloat( "CfgVehicles " + attachment.GetType() + " radiationProtection" ) * state);
			}
		}
		
		ItemBase gasMaskFilter = GetGasMaskFilter();
		if (gasMaskFilter && gasMaskFilter.GetQuantity() > 0)
		{
			value = value + GetGame().ConfigGetFloat( "CfgVehicles " + gasMaskFilter.GetType() + " radiationProtection" );
		}
		
		return Math.Clamp(value, 0, 1);
	}
	
	override bool CanBeTargetedByAI(EntityAI ai)
	{
		return !IsDamageDestroyed();
	}
	
	void MarkAsNPC()
	{
		m_isNPC = true;
		SetSynchDirty();
	}
};