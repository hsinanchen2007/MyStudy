### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        Map map = new HashMap();
        String[] a = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int[] b = {1,3,5,8,10,30,50,80,100,300,500,800,1000};
        for (int i = 0;i<a.length;i++){
            map.put(a[i],b[i]);
        }

        String[] ss = s.split("");
        int num = 0;
        for (int i = 0; i<ss.length;i++){
            //判断当前位置与前一位置数据的构成是否在字典中(判断特殊情况)
            if(i>0 && map.get(ss[i-1]+ss[i]) != null){
                num += (int)map.get(ss[i-1]+ss[i]);
                continue;   
            }
            num = num + (int)map.get(ss[i]);
        }
    return num;
    }
}
```