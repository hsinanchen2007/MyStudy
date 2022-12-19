题目链接:<https://leetcode-cn.com/problems/maximum-score-words-formed-by-letters/>  

题目很长，本场比赛作为压轴题，理解题意后其实就是对words满足条件的子集中选出分数最高的组合，对于每个单词有两种选择，拼写或者不拼写，拼写则消耗掉对应的字母，words最大长度为15，数据规模不大，可以采用递归，万能回溯大法，注意不拼写的时候需要先还原消耗掉的字母
```
func dfs(words []string,k int,n int,storage *[]int,ans *[]string,score []int,maxScore *int) {
    //如果某个字母剩余使用个数小于0直接return
	if !check(storage){
		return
	}
	if k == n{
		//fmt.Println(*ans)
		sum := 0
		for _,str := range *ans{
			for _,v := range  str{
				sum += score[v - 97]
			}
		}
		if sum > *maxScore{
			*maxScore = sum
		}
		return
	}
	//拼写该单词消耗字母
	cost(words[k],storage)
	*ans = append(*ans,words[k])
	dfs(words,k +1,n,storage,ans,score,maxScore)
	//不拼写该单词需要先还原消耗掉的字母
	recover(words[k],storage)
	*ans = (*ans)[:len(*ans) - 1]
	dfs(words,k +1,n,storage,ans,score,maxScore)
}

func check(storage *[]int)bool{
	for _,v := range *storage{
		if v < 0{
			return false
		}
	}
	return true
}

func cost(str string,storage *[]int){
	for _,v := range str{
		(*storage)[v - 97]--
	}
}

func recover(str string,storage *[]int){
	for _,v := range str{
		(*storage)[v - 97]++
	}
}


func maxScoreWords(words []string, letters []byte, score []int) int {
	ans := make([]string,0)
	storage := make([]int,26)
	for _,v := range letters{
		storage[v - 97]++
	}
	maxScore := 0
	dfs(words,0,len(words),&storage,&ans,score,&maxScore)
	return maxScore
}
```