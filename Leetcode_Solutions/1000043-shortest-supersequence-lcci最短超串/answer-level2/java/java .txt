### 解题思路
hashmap+滑动窗口

### 代码

```java
class Solution {
    public int[] shortestSeq(int[] big, int[] small) {
        HashMap<Integer,Integer> s=new HashMap<>();
        //ArrayList window=new ArrayList();
        for(int i=0;i<small.length;i++)
        {
            //int cnt=s.getOrDefault(small[i],0);
             s.put(small[i],0);
        }
        int []result={-1,-1};
        int []noResult={};
        int left=0,right=0,count=0,result_l=-1,result_r=-1,minLen=999999;
        while(right<big.length)
        {
            int cur=big[right];
            if(s.containsKey(cur))
            {
                if(s.get(cur).intValue()==0)
                count++;
                s.put(cur,s.get(cur).intValue()+1);
            }
            while(count==small.length)
            {
                
                int temp=big[left];
                if(!s.containsKey(temp) || s.get(temp).intValue()>1)
                {
                    left++;
                    if(s.containsKey(temp))
                    s.put(temp,s.get(temp).intValue()-1);
                   
                }
                else
                {
                    if(minLen>right-left+1)
                    {
                        minLen=right-left+1;
                        result_l=left;
                        result_r=right;

                    }
                    s.put(temp,s.get(cur).intValue()-1);
                    left++;
                    count--; 
                }
              
            }
              right++;
        }
        result[0]=result_l;
        result[1]=result_r;

        return minLen==999999?noResult:result;


    }
}
```