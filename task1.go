package main

import (
	"fmt"
	"math"
)

func table() {
	fmt.Println("|    x    |     y     |")
	fmt.Println("------------------------")
}

func printTable(x, y float64) {
	fmt.Printf("|%8.1f |%10.2f |\n", x, y)
}

func printEnd() {
	fmt.Println("------------------------")
}

func main() {
	fmt.Println("Таблица значений функции:")

	printEnd()
	table()

	dx := 0.5
	var x, y float64

	// 1. Прямая [-5; -2]
	for x = -5; x < -2; x += dx {
		y = -x - 2
		printTable(x, y)
	}

	// 2. Четверть окружности [-2; -1]
	for x = -2; x < -1; x += dx {
		y = math.Sqrt(1 - math.Pow(x+1, 2))
		printTable(x, y)
	}

	// 3. Горизонтальный участок [-1; 1]
	for x = -1; x < 1; x += dx {
		y = 1
		printTable(x, y)
	}

	// 4. Прямая [1; 2]
	for x = 1; x < 2; x += dx {
		y = -2*x + 3
		printTable(x, y)
	}

	// 5. Парабола [2; 6]
	for x = 2; x <= 6; x += dx {
		y = math.Pow(x-2, 2)/8 - 1
		printTable(x, y)
	}

	printEnd()
}
