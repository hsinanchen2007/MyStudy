方法1：双vector

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了23.68%的用户

```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> pre_row;//用来容纳上一行的元素
        int row = 0;
        
        while(row <= rowIndex){//通过计算和迭代生产数组
            
            vector<int> next_row(row+1);//初始化下一行，容量为前一行的大小+1
            
            for(int i=0; i<=row; i++){
                
                if(i==0 || i==row)//首、末位的元素为1
                    next_row[i] = 1;
                
                else{
                    
                    next_row[i] = pre_row[i-1] + pre_row[i];//中间的元素值为上一行对应位置左右元素的和
                }
            }
            
            //pre_row.clear();
            pre_row.swap(next_row);//将生成好的新行替换旧行
            row++;//行数+1
        }

        
        return pre_row;
        
    }
};
```


方法2：单vector

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了31.78%的用户


```
class Solution {
public:
    vector<int> getRow(int rowIndex) {

        int row = 0;
        vector<int> next_row(rowIndex+1);
        
        while(row <= rowIndex){//通过计算和迭代生产数组
            
            for(int i=row; i>=0; i--){
                
                if(i==0 || i==row)//首、末位的元素为1
                    next_row[i] = 1;
                
                else{
                    
                    next_row[i] = next_row[i-1] + next_row[i];//中间的元素值为上一行对应位置左右元素的和
                }
            }
            row++;//行数+1
        }

        
        return next_row;
        
    }
};
```
