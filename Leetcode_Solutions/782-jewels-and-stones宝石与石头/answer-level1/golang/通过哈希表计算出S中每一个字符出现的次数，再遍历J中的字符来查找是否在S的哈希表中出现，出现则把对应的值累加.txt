package main

import "fmt"


func main() {
	J := "aA"
	S := "aAAbbbb"
	count := numJewelsInStones(J, S)
	fmt.Println(count)
}

func numJewelsInStones(J string, S string) int {
	count := 0
	myMap := make(map[string]int, len(S))
	for _, v := range S {
		myMap[string(v)]++
	}
	for _, v := range J {
		if value, ok := myMap[string(v)]; ok {
			count += value
		}
	}
	return count
}
