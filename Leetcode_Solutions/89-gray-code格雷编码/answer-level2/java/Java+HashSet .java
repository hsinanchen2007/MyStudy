### 解题思路
此处撰写解题思路
1.将0，1序列存储在数组中，从右到左扫描，依次更改元素的值，如果产生新的序列则加入到结果中，否则指针向左移动
2.将序列转换成数字

这里产生的每一个序列都先转化为字符串，然后存在哈希表中。

### 代码

```java
class Solution {
    public List<String> grayStrings=new ArrayList<>();
    public Set<String> set=new HashSet<>();
    public List<Integer> result=new ArrayList();
    public List<Integer> grayCode(int n) {
        if(n==0){
            result.add(0);
            return result;
        }
        int[] array=new int[n];
        Arrays.fill(array,0);
        grayStrings.add(arrayToString(array));
        set.add(arrayToString(array));
        int number=1;
        while(true){
            for(int i=array.length-1;i>=0;i--){
                if(array[i]==0){
                    array[i]=1;
                    String cur=arrayToString(array);
                    if(!set.contains(cur)){
                        set.add(cur);
                        grayStrings.add(cur);
                        number++;
                        break;
                    }
                    else{
                        array[i]=0;
                    }
                }
                else{
                    array[i]=0;
                    String cur=arrayToString(array);
                    if(!set.contains(cur)){
                        set.add(cur);
                        grayStrings.add(cur);
                        number++;
                        break;
                    }
                    else{
                        array[i]=1;
                    }
                }
            }
            if(number==Math.pow(2,n)){
                break;
            }
        } 
        for(int i=0;i<grayStrings.size();i++){
            result.add(stringToNumber(grayStrings.get(i)));
        }
        return result;
    }
    public String arrayToString(int[] array){
        String result="";
        for(int i=0;i<array.length;i++){
            result=result+String.valueOf(array[i]);
        }
        return result;
    }
    public int stringToNumber(String s){
        int result=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s.charAt(i)=='1'){
                result=result+(int)Math.pow(2,s.length()-i-1);
            }
        }
        return result;
    }
}
```