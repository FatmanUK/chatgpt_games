package main

import (
    "fmt"
)

var board = [3][3]string{
    {" ", " ", " "},
    {" ", " ", " "},
    {" ", " ", " "},
}

var player = "X"

func main() {
    for {
        printBoard()

        fmt.Print("Enter row: ")
        var row int
        fmt.Scan(&row)

        fmt.Print("Enter col: ")
        var col int
        fmt.Scan(&col)

        if board[row][col] != " " {
            fmt.Println("Invalid move, try again.")
            continue
        }

        board[row][col] = player

        if checkWin() {
            fmt.Printf("Player %s wins!\n", player)
            break
        }

        if checkDraw() {
            fmt.Println("It's a draw!")
            break
        }

        if player == "X" {
            player = "O"
        } else {
            player = "X"
        }
    }
}

func printBoard() {
    for i := 0; i < 3; i++ {
        fmt.Println("---+---+---")
        fmt.Printf(" %s | %s | %s \n", board[i][0], board[i][1], board[i][2])
    }
    fmt.Println("---+---+---")
}

func checkWin() bool {
    for i := 0; i < 3; i++ {
        if board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != " " {
            return true
        }
    }

    for i := 0; i < 3; i++ {
        if board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != " " {
            return true
        }
    }

    if board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != " " {
        return true
    }

    if board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != " " {
        return true
    }

    return false
}

func checkDraw() bool {
    for i := 0; i < 3; i++ {
        for j := 0; j < 3; j++ {
            if board[i][j] == " " {
                return false
            }
        }
    }
    return true
}

