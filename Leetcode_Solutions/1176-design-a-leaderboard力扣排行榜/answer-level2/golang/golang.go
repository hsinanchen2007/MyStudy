简单排序
```
type Leaderboard struct {
    item []Item
    exists map[int]bool
}

type Item struct {
    score int
    id int
}

func Constructor() Leaderboard {
    return Leaderboard{
        item: []Item{},
        exists: map[int]bool{},
    }
}


func (this *Leaderboard) AddScore(playerId int, score int)  {
    if _, ok := this.exists[playerId]; !ok {
        this.exists[playerId] = true
        this.item = append(this.item, Item{score, playerId})
    } else {
        for i := 0; i < len(this.item); i++ {
            if this.item[i].id == playerId {
                this.item[i].score += score
                break
            }
        }
    }
}


func (this *Leaderboard) Top(K int) int {
    sort.Slice(this.item, func(i, j int) bool {
        return this.item[i].score > this.item[j].score
    })
    score := 0
    for i := 0; i < K; i++ {
        score += this.item[i].score
    }
    return score
}


func (this *Leaderboard) Reset(playerId int)  {
    for i := 0; i < len(this.item); i++ {
        if this.item[i].id == playerId {
            this.item[i].score = 0
            break
        }
    }
}
```
