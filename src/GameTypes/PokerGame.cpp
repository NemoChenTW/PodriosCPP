/*
 * PokerGame.cpp
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#include "PokerGame.h"
#include <iostream>

#include "GameTools/CardDeck/PokerCard/PokerCard.h"

PokerGame::PokerGame(PokerGameType pokerGameType)
:_pokerGameType(pokerGameType)
{
	LOG_TRACE("Construct PokerGame.");

	setGameRule();
}

PokerGame::~PokerGame()
{
	// TODO Auto-generated destructor stub
}

///		Initial the game tool "CardDeck"
void PokerGame::initialGameTool(GameTool *cardDeck)
{
	cardDeck = new CardDeck();
	generatePokerCard(cardDeck);
	//TODO 發牌
}

/**
 * @brief	Shuffle poker card deck.
 *
 * @param 	cardDeck Input poker card deck.
 */
void PokerGame::shuffle(GameTool *cardDeck)
{
	CardDeck *pokerCardDeck = (CardDeck*) cardDeck;

	//TODO Shuffle the poker card.

}

/**
 * @brief	Generate Poker cards and put them into card deck.
 *
 * @param 	cardDeck	Card deck to store poker cards.
 */
void PokerGame::generatePokerCard(GameTool *cardDeck)
{
	CardDeck *pokerCardDeck = (CardDeck*) cardDeck;

	for(const auto &suit :Poker::Suit() )
	{
		for(const auto &point :Poker::Point() )
		{
			pokerCardDeck->push_back(new PokerCard(suit, point));
			cout << Poker::enum2str(suit)
			<< ", " << Poker::enum2str(point) << endl;
		}
	}
	cardDeck->show();
}

/**
 * 	@brief		Set the game rule according to the _pokerGameType
 */
void PokerGame::setGameRule()
{
	LOG_TRACE("Set game as PokerGame BigDeuce.");
	if(_pokerGameType == PokerGameType_BigDeuce)
	{
		setBigDeuceGameRule();
	}

}

/**
 * 	@brief		Set the game rule of game big deuce
 */
void PokerGame::setBigDeuceGameRule()
{
	LOG_TRACE("Set BigDeuce game rule.");
	_numberOfMinPlayers = 2;
	_numberOfMaxPlayers = 4;
	_numberOfInitialCards = 13;
}
