### 解题思路
例如： [3,30,34,5,9] 
现将其转换为一个数组列表list
调用list.sort(Comparator<? super E> c)方法
怎么自定义比较器？
对于['10', '2'] 最小值是102
那么'10' + '2' < '2' + '10' 时我们希望'10'放在最终值的左边，'2'放右边
即这是升序的，按此种排序规则 '10' < '2'
因此 '10' + '2' < '2' + '10' compare()返回 -1
反之， 返回 1

### 代码

```java
class Solution {
    public String minNumber(int[] nums) {       
        List<String> list = new ArrayList();
        for(int i : nums){
            list.add(String.valueOf(i));
        }
        //lambda表达式
        list.sort((String v1, String v2) -> (v1+v2).compareTo(v2+v1));


        /*一种写法
        //int compare(Object o1, Object o2)
        //list.sort(Comparator<? super E> c)
        list.sort(new Comparator<String>(){
            @Override
            public int compare(String v1, String v2){
                //升序排列的时候，v1>v2才返回1
                // 10 2 
                // "102" < "210" => 10 v1
                String str1 = v1 + v2;
                String str2 = v2 + v1;
                if(str1.compareTo(str2) <= 0){
                    return -1;//希望将v1排在前面，升序返回-1
                }else{
                    return 1;
                }
            }
        });
        */
        StringBuilder sb = new StringBuilder("");
        for(String str : list){
            sb.append(str);
        }
        return sb.toString();
    }
}
```