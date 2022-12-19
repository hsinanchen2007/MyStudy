```
class Solution 
{
    public int[] relativeSortArray(int[] arr1, int[] arr2) 
    {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        int[] list = new int[arr1.length];
        for(int i =0;i<arr1.length;i++)
        {
            if(map.containsKey(arr1[i]))
            {
                map.put(arr1[i],map.get(arr1[i])+1);
            }else
            {
                map.put(arr1[i],1);
            }
        }
        int k =0;
        for(int j = 0;j<arr2.length;j++)
        {

            while(map.get(arr2[j])>0)
            {
                list[k++]=arr2[j];
                map.put(arr2[j],map.get(arr2[j])-1);
            }

        }
        Arrays.sort(arr1);
        for(int i=0;i<arr1.length;i++)
        {
            if(map.get(arr1[i])>0)
            {
                list[k++] = arr1[i];
                map.put(arr1[i],map.get(arr1[i])-1);
            }
        }
        return list;
    }
}
```






执行用时 :
        6 ms, 在所有 Java 提交中击败了72.90%的用户
        内存消耗 :
        36.7 MB ,在所有 Java 提交中击败了100.00%的用户