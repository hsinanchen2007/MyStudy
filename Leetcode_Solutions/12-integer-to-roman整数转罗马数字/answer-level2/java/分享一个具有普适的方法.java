题目的限制是在3999之内，如果取消这个限制呢。（以下是我脑补场景的解决方案）
使用数组保存每个罗马对应的数字，包括六个特殊情况。使用map保存数字对应的个数。
六个特殊情况和出现5的情况，如果有都只会出现一次，那么这个东西其实很好写。

```
int[] limit={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        Map<Integer,Integer> map=new LinkedHashMap<>();
        while(num>0){
            for (int i=limit.length-1;i>=0;i--){
                if (num<limit[i])
                    continue;
                map.put(limit[i],num/limit[i]);
                num=num%limit[i];
            }
        }
        StringBuilder builder=new StringBuilder();
        for (Map.E***y<Integer,Integer> e***y:map.e***ySet()){
            int key=e***y.getKey(),value=e***y.getValue();
            if (key==1000)builder.append("M".repeat(value));
            else if (key==900)builder.append("CM");
            else if (key==500)builder.append("D");
            else if (key==400)builder.append("CD");
            else if (key==100)builder.append("C".repeat(value));
            else if (key==90)builder.append("XC");
            else if (key==50)builder.append("L");
            else if (key==40)builder.append("XL");
            else if (key==10)builder.append("X".repeat(value));
            else if (key==9)builder.append("IX");
            else if (key==5)builder.append("V");
            else if (key==4)builder.append("IV");
            else if (key==1)builder.append("I".repeat(value));
        }
        return builder.toString();
```
代码中jdk12在String类中新增repeat方法，因为官网是jdk8的，需要自实现repeat方法
结果：
执行用时 : 36 ms, 在Integer to Roman的Java提交中击败了67.47% 的用户
内存消耗 : 45.2 MB, 在Integer to Roman的Java提交中击败了68.34% 的用户
增加了普适性，故而失去了性能。
如果有大神能够在此场景下优化能力，请分享。