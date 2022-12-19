### 解题思路
通过位运算遍历所有字符串连接的情况，左移1来判断当前情况获取的字符串索引，通过字符型HashSet来保存连接的字符串，如果HashSet中包含某个字符则跳出循环，否则add添加字符来连接，记录最大长度

### 代码

```java
class Solution {
    public int maxLength(List<String> arr) {
        //i < (1 << n)表示i小于2^n,若n为4,i最大值为1111
        //(i & (1<<j)) > 0判断i右边j位(从0开始)为1
        int n = arr.size();//获取list的长度
        int maxLength = 0;
        for(int i = 0; i < (1 << n); i++){//遍历运算存在的情况数
            HashSet<Character> hs = new HashSet<>();
            boolean ok = true;
            for(int j = 0; j < n; j++){//遍历左移位数
                if((i & (1 << j)) > 0){//i的左移第j位为1
                    String ss = arr.get(j);//取第j个字符串
                    for(int k = 0; k < ss.length(); k++){//遍历第j个字符串
                        if(hs.contains(ss.charAt(k))){
                            ok = false;
                            break;
                        }else{
                            hs.add(ss.charAt(k));//不包含就添加到hs中
                        }
                    }
                }
            }
            if(ok){
                maxLength = Math.max(maxLength, hs.size());//set长度
            }
        }
        return maxLength;
    }
}
```