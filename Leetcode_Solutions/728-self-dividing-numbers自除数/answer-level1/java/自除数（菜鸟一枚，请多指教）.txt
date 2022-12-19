### 解题思路
此处撰写解题思路
从left到right遍历，将每一个元素转为一个字符串，遍历字符串，通过对每个字符判断，如果值为‘0’或者转为数字之后能被该元素整除，则退出当前循环，执行下一次循环。如果最后遍历到字符串末尾，则将元素添加到链表中。最后打印链表
### 代码

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> list=new ArrayList<>();
            for(int i=left;i<right+1;i++){
                String data=String.valueOf(i);
                for(int j=0;j<data.length();j++){
                    if(data.charAt(j)=='0'){
                        break;
                    }else if(i%Integer.valueOf(data.charAt(j)-48)!=0){
                        break;
                    }if(j==data.length()-1){
                        list.add(i);
                    }
                }           
            }
        return list;
    }
}
```