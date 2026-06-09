### 解题思路
所有解题思路都在  f[i,j]=f[i-1,j-1]+f[i-1,j-1]

### 代码

```java
class Solution {
      public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list =new ArrayList<>();
        for(int i=0;i<numRows;i++){ //每行的个数
            if(i==0){ //初始化第一行
                List<Integer> templist =new ArrayList<Integer>();
                templist.add(1);
                list.add(templist);
            }else{   //其他行初始化
                List<Integer> templist =new ArrayList<Integer>();
                for(int j=0;j<i+1;j++){
                    if(j==0||j==i){
                        templist.add(1);  //精华点1   每行第一个最后一个是 1
                    }else{
                        List<Integer>  shangyihang =list.get(i-1);
                          //精华点2 F[i,j]=f[i-1,j-1]+f[i-1,j-1]; 也就是他上一行相邻两元素
                        templist.add(shangyihang.get(j-1)+shangyihang.get(j)); 
                    }

                }
                list.add(templist);
            }
        }

        return list;
      }
}
```