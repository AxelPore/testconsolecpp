#include <print>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>

enum ScoreValue : uint8_t { LOVE = 0, FIFTEEN = 1, THIRTY = 2, FOURTY = 3 };

[[nodiscard]] std::string score_message(ScoreValue score)
{
    switch (score)
    {
    case LOVE: return "LOVE";
    case FIFTEEN: return "FIFTEEN";
    case THIRTY: return "THIRTY";
    case FOURTY: return "FOURTY";
    default: assert(false && "Score unexpected"); return "";
    }
}

[[nodiscard]] std::string tennis_score(uint8_t player1Score, uint8_t player2Score)
{
    if (player1Score == player2Score)
    {
        if (player1Score >= 3)
            return "DEUCE";
        else
            return score_message(static_cast<ScoreValue>(player1Score)) + "-All";
    }

    return score_message(static_cast<ScoreValue>(player1Score)) + "-"
        + score_message(static_cast<ScoreValue>(player2Score));
}


int main()
{
	std::println("Tennis Score is : {}", tennis_score(2, 2));
}