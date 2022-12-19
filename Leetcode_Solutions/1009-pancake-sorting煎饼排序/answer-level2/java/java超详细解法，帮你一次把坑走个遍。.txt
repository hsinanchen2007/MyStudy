java超详细解法，帮你一次把坑走个遍。  
终于刷到一道好题。这题的坑是一层套着一层。  
首先说一下核心思路，就是先找到当前最大值，然后将最大值翻转到数组最后一位。  
以3241举例。  
1.先找到当前最大的数4，    
2.将4及其之前的数进行翻转,  
3.将整个数组（不包括比当前最大值大的值）进行翻转，  
**第一个坑**，当我们找的是最大值4的时候，当然是将整个数组翻转，但当我们找到的当前最大值为3的时候，就不能将整个数组进行翻转了，而是翻转整个数组不包括最后一位，以此类推。  
**第二个坑**，我们如何每次都找到当前的最大值呢。我的思路是让B数组拷贝A数组，然后将B数组进行排序，然后每次在A数组中去找B数组中的当前最大值，比如第一次寻找的就是B数组的最后一位，之后就是倒数第二位以此类推。  
**第三个坑**，我们需要翻转数组， 判断条件为：i<(times+1)/2;要注意是times+1，我这里的times就是位置，也就是说需要翻转times之前及times的数。times+1可以有效地避免times为奇数（3，其实需要翻转的有0，1，2，3四个）的情况，而times为偶数也无妨，times/2与（times+1）/2结果相同。  
**第四个坑**我们需要判断当前的位置是否是正确的位置，如果是正确的位置，就不需要向list中添加数据，如果是错误的，就添加两次数据，但会忽略，还有一种情况是当前最大值已经在数组的第1位了，这种情况我们只翻转一次，也就是向list添加一次数据即可。  
```java
class Solution {
    public List<Integer> pancakeSort(int[] A) {
        int times=0;
        List<Integer>list=new ArrayList<>();
        int[]B=Arrays.copyOf(A,A.length);
        Arrays.sort(B);
        for(int i=0;i<A.length;i++)
        {
            times = findMax(A,B,i);
            if(times!=-1){
                if(times!=0){
                 reverse(A,times);
             list.add(times+1);
                }
                //如果当前最大值位置等于0，就可以直接全部翻转
                
                reverse(A,A.length-i-1);
                list.add(A.length-i);
                
        }
        }
        return list;
        
    }
    public int findMax(int[]A,int[]B,int curr)
    {
        int num=B[B.length-curr-1];
        int index=0;
        for(int i=0;i<A.length;i++)
        {
            if(A[i]==num)
            {  
            index=i;
             break;
            }
            
        }
        if(B.length-curr-1==index)
            return -1;
 
        return index;
    }
    public int[] reverse(int[]A,int times)
    {
        for(int i=0;i<(times+1)/2;i++)
        {
            int temp=A[i];
            A[i]=A[times-i];
            A[times-i]=temp;
        }
        return A;
    }
}
```
