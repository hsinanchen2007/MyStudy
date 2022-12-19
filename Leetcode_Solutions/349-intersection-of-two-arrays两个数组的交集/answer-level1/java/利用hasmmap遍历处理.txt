1、使用了hashmap中的containsKey方法来判断map中是否含有指定的key值
2、注意map中元素的迭代方法：
    对key值的迭代：for(type factor : map.keySet())
    对value值的迭代：for(type factor : map.values())
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) { 
            int len1 = nums1.length;
            int len2 = nums2.length;
            int len = len1 > len2?len1:len2;
            HashMap<Integer,Integer> map = new  HashMap<Integer,Integer>();
            HashMap<Integer,Integer> resultMap = new  HashMap<Integer,Integer>();
            for(int i = 0; i < len1; i++){
                if(!map.containsKey(nums1[i])){
                    map.put(nums1[i],i);
                }
            }
            for(int j = 0; j < len2; j++){
                if(map.containsKey(nums2[j]) && !resultMap.containsKey(nums2[j])){
                    resultMap.put(nums2[j],j);
                }
            }
            int [] result = new int[resultMap.size()];
            int k = 0;
            for(Integer tem : resultMap.keySet()){
                result[k] = tem;
                k++;
            }
            return result;
    }
}