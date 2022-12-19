### 解题思路
#使用一个二维数组nums进行第一次数据存放
数组中保存3种信息（nums长度与字符串长度相同）：
（1）元素在字符串中出现的起始位置。nums[i][0]!=0就说明存在一个化学元素从i开始，非化学元素或小写字母出现位置，一律为0；
（2）元素的终止位置nums[i][1]，利用起始位置和终止位置记录最终化学元素的字符串表示。
（3）元素的数量nums[i][0]。
#使用栈来进行括号的匹配
括号匹配略。
由于nums中非化学元素或小写字母出现位置，一律为0，所以直接对nums中起始和终止位置之间的值乘以相应的倍数，0*任意数=0
#使用TreeMap进行排序，以及输出
直接看代码，很简单
### 代码

```java
class Solution {
    public String countOfAtoms(String formula) {
        int n=formula.length();
        int[][] nums=new int[n][2];//修改为二维数组，第一位存放数量，第二位存放end位置
        int i=0;
        LinkedList<Integer> stack=new LinkedList<>();
        char tem;
        int index;
        int n_index;//记录数字的起始位置
        int k,ki,end;
        while(i<n){
            tem=formula.charAt(i);
            if (tem>='A' && tem<='Z'){//遇到大写字母
                nums[i][0]=1;
                index=i;//记录当前位置
                while(i+1<n &&(formula.charAt(i+1)>='a' && formula.charAt(i+1)<='z')){
                    //虽然化学元素最多只有一个小写字母，但还是用个循环吧
                    i++;
                }
                nums[index][1]=i+1;
                //数字可以不是个位的
                n_index=i+1;
                while(i+1<n && formula.charAt(i+1)>='0' && formula.charAt(i+1)<='9'){
                    i++;
                }
                if (n_index<i+1){
                    nums[index][0]*=Integer.parseInt(formula.substring(n_index,i+1));
                }


            }else if (tem=='('){//遇到左括号
                stack.add(i);
            }else if(tem==')'){ //遇到右括号
                k=stack.removeLast();
                n_index=i+1;
                while(i+1<n && formula.charAt(i+1)>='0' && formula.charAt(i+1)<='9'){
                    i++;
                }
                if (n_index<i+1){
                    ki=Integer.parseInt(formula.substring(n_index,i+1));
                    for (int j = k; j <n_index ; j++) {
                        nums[j][0]*=ki;
                    }
                }
            }
            i++;
        }
        TreeMap<String,Integer> map=new TreeMap<>();
        String temp;
        for (int j = 0; j <nums.length ; j++) {

            if (nums[j][0]>0){
                temp=formula.substring(j,nums[j][1]);
                if (map.containsKey(temp)){
                    map.put(temp,map.get(temp)+nums[j][0]);
                }else{
                    map.put(temp,nums[j][0]);
                }

            }
        }
        StringBuilder str=new StringBuilder();
        for (String st :map.keySet()){
            str.append(st);
            if (map.get(st)>1){
                str.append(map.get(st));
            }
        }
        return str.toString();
    }
}
```