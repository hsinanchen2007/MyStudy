### 解题思路
借鉴github上大神的思路，整理了一下发出来，还有很多不足，欢迎指正
![微信截图_20200305101122.png](https://pic.leetcode-cn.com/564ecb873e4eb2e2fae424579c713e487e6fd8d0cafe257650b5b6d4caa0c2af-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200305101122.png)


### 代码

```golang

func solveSudoku(board [][]byte)  {
	// 三个布尔数组 表明 行, 列, 还有 3*3 的方格的数字是否被使用过
	var (
		rowUsed [9][10]bool
		listUsed [9][10]bool
		chunkUsed [3][3][10]bool
	)
	//初始化
	for i:=0;i<9;i++{
		for j:=0;j<9;j++{
			num:=board[i][j]-'0'
			if num>0&&num<10{
				rowUsed[i][num]=true
				listUsed[j][num]=true
				chunkUsed[i/3][j/3][num]=true
			}
		}
	}
	//	尝试填充数组
	(recall(0, board, rowUsed, listUsed, chunkUsed))

}

func recall(n int,board [][]byte,rowUsed [9][10]bool,listUsed [9][10]bool,chunkUsed [3][3][10]bool)bool{
	if n==81{//表示已经填充完成
		return true
	}
	row:=n/9
	list:=n%9

	//如果有数字通过，则n+1
	if board[row][list] !='.'{ //如果为'.'
		return recall(n+1,board,rowUsed,listUsed,chunkUsed)
	}else{
		chunk_row:=row/3
		chunk_list:=list/3
		for num:=1;num<=9;num++{
			if !rowUsed[row][num] && !listUsed[list][num] && !chunkUsed[chunk_row][chunk_list][num]{
				//说明该数字在该行，列，块里面都没有,就将这数字填充
				board[row][list]=byte(num+'0')
				rowUsed[row][num],listUsed[list][num],chunkUsed[chunk_row][chunk_list][num]=true,true,true

				//然后开始下一个填充
				if recall(n+1,board,rowUsed,listUsed,chunkUsed){
					return true
				}
					rowUsed[row][num],listUsed[list][num],chunkUsed[chunk_row][chunk_list][num]=false,false,false
			}
	}
		board[row][list]='.' //否则当前填充失败，退回
	}
	return false
}
```