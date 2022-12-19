### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
	public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> answer = new ArrayList<>();

        //如果函数为零，直接返回
        if(numRows == 0)
        {
        	return answer;
        }       
        //向answer中添加数组
        //因为第一行不符合以后每行添加的规律，所以先添加好
        answer.add(Arrays.asList(1));
        //外层数组控制行数
        for(int i=1;i<numRows;i++)
        {
            List<Integer> tempList  = new ArrayList<>();
            for(int j=0;j<=i;j++)
            {
            	//每行的第一个和最后一个都是1
            	if(j==0 || j==i)
            	{
            		tempList.add(1);
            	}else{
            	//获取上一行的数组
            	List<Integer> preList=answer.get(i-1);
            	tempList.add(preList.get(j)+preList.get(j-1));
                }
            }
            answer.add(tempList);
            
        }
        return answer;

    }
}
```