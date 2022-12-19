```golang
func deckRevealedIncreasing(deck []int) []int {
	sort.Ints(deck[:]) //从小到大排序
	ret := deck[len(deck)-1:]
	deck = deck[:len(deck)-1]
	for len(deck) > 0 {
		//ret前后换
		ret = append(ret[len(ret)-1:], ret[:len(ret)-1]...)
		ret = append(deck[len(deck)-1:], ret[:]...)
		deck = deck[:len(deck)-1]
	}
	return ret
}
```