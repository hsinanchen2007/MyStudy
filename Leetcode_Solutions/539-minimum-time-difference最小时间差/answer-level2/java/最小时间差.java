### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMinDifference(List<String> timePoints) {
        int []count=new int[timePoints.size()];
        int []number=new int[timePoints.size()];
        int min=Integer.MAX_VALUE,len=0;
        for(int i=0;i<timePoints.size();i++){
        count[i]=(timePoints.get(i).charAt(0)-'0')*10+timePoints.get(i).charAt(1)-'0';
        number[i]=(timePoints.get(i).charAt(3)-'0')*10+timePoints.get(i).charAt(4)-'0';
        if(count[i]==0)
        count[i]=24;
        if(number[i]==0){
        number[i]=60;
        count[i]--;
        }
        }
        for(int i=0;i<timePoints.size();i++){
            len=(count[i])*60+number[i];
            count[i]=len;
        }
        Arrays.sort(count);
        for(int i=0;i<count.length-1;i++){
            len=count[i+1]-count[i];
            if(len>720)
            len=1440-len;
            if(len<min)
            min=len;
        }
        len=count[count.length-1]-count[0];
        if(len>72)
        len=1440-len;
        if(min<len)
        return min;
        else return len;
    }
}
```