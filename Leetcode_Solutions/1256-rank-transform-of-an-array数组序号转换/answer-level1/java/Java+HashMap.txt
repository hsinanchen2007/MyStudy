执行用时 :35 ms, 在所有 Java 提交中击败了84.81% 的用户
内存消耗 :55.6 MB, 在所有 Java 提交中击败了100.00%的用户

class Solution {
    public int[] arrayRankTransform(int[] arr) {
       int i=0;
       int n[]=new int[arr.length];
       int arr1[]=Arrays.copyOf(arr,arr.length);
       Arrays.sort(arr1);    //先排个序
       Map<Integer,Integer> hm=new HashMap<>();
       int count=1;
       for(i=0;i<arr1.length;i++)    //把下标存入HashMap
       {
           if(hm.containsKey(arr1[i]))
              continue;       
            else{
                hm.put(arr1[i],count);
                count++;
            }
       }
       for(i=0;i<arr.length;i++)
       {
           n[i]=hm.get(arr[i]);
       }
       return n;
    }
}