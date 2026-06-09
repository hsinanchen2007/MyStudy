### 解题思路
此处撰写解题思路
1.判断行重复
2.判断列重复
3.判断九宫格重复
时间复杂度和空间复杂度均为O(1)
### 代码

```csharp
public class Solution {
    public bool IsValidSudoku(char[][] board) {
        HashSet<int>[] rows=new HashSet<int>[9];
        HashSet<int>[] cols=new HashSet<int>[9];
        HashSet<int>[] boxs=new HashSet<int>[9];
       
        for(int i=0;i<9;i++){
            rows[i]=new HashSet<int>();
            cols[i]=new HashSet<int>();
            boxs[i]=new HashSet<int>();
        }
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char cur=board[i][j];
                if(cur!='.'){
                    int num=(int)cur;
                    int boxindex=(i/3)*3+(j/3);
                    bool rowexists=rows[i].Contains(num);
                    bool colexists=cols[j].Contains(num);
                    bool boxexists=boxs[boxindex].Contains(num);
                    if(rowexists || colexists || boxexists){
                        return false;
                    }
                    rows[i].Add(num);
                    cols[j].Add(num);
                    boxs[boxindex].Add(num);
                }
            }
        }
        return true;
    }
}
```