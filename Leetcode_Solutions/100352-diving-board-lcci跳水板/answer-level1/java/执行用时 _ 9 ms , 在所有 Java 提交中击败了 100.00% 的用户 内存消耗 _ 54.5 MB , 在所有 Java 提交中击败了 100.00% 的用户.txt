### 解题思路
1.短的木板shorter和 较长的木板longer 使用的数目之和是k
2.列出所有可能的结果（先不管是否重复）
3.从小到大排序Arrays.sort(arr)
4.对所有存在的结果进行去除重复元素的操作
注：去重我本想用Set集合操作，但是返回值类似是Object类型，不符合int类型，希望各位兄弟可以指点一二，谢谢了

### 代码

```java
class Solution {
    public int[] divingBoard(int shorter, int longer, int k) {
        if( k == 0){
            return new int[0];
        }
        int[] arr = new int [k + 1];
        for(int i = 0 ; i <= k ; ++ i){
            arr[i] = shorter * (k - i)  +  longer * i ;
        }
        Arrays.sort(arr);
        int j = 0;
        for(int i = 0; i < k ; ++i ){
            if(arr[i] != arr[ i + 1]){
                arr[j++] = arr[i];
            }
        }
        arr[j] = arr[k];
        int[] arrs = new int [j + 1];
        for(int i = 0 ; i <= j ; ++ i){
            arrs[i] = arr[i];
        }
        return arrs;
        /* //Object[] toArray()    返回一个包含此集合中所有元素的数组 
        Set set = new HashSet();
        for(int i = 0 ; i < arr.length ; ++i){
            set.add(arr[i]);
        }
        //String str=obj.toString();
        //int size()    返回此集合中的元素数（其基数）。 
        return (int)(set.toArray()); //强制转换不了  */
    }
}
```