### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String[] permutation(String S) {
        char[] arr = S.toCharArray();
        ArrayList<char[]> list = new ArrayList<>();
        for(int i = 0; i < arr.length; i++){
            if(i == 0){
                char[] origin = new char[1];
                origin[0] = arr[0];
                list.add(origin);
            }else {
                ArrayList<char[]> tmp = new ArrayList<>();//创建临时集合
                for(int j = 0; j < list.size(); j++){
                    char[] sb = list.get(j);//从list中取一个
                    
                    for(int k = 0; k < (sb.length + 1); k++){//新插入的字符可以在0~（c.length-1）中的任意位置
                        char[] c = new char[sb.length + 1];//临时数组，长度为取出来的sb加1
                        c[k] = arr[i];//插入
                        int k2 = 0;//数组c的索引
                        int offset = 0;//字符串sb的索引
                        while(k2 < c.length){//按顺序插入剩余字符
                            if(k2 != k){
                                c[k2] = sb[offset++];
                            }
                            k2++;
                        }
                        tmp.add(c);//新生产的字符数组加入临时集合中
                    }
                }
                list = tmp;//将原集合替换成新的
            }
        }
        String[] strs = new String[list.size()];
        for(int of = 0; of < list.size(); of++){
            strs[of] = new String(list.get(of));
        }
        return strs;
    }
    


}
```