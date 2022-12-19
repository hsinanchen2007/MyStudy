### 解题思路
此处撰写解题思路
 算法比较垃圾 就是穷举
### 代码

```java
class Solution {
   static class Data {
        char s;
        int value;
        public Data(char s,int v){
            this.s =s;
            this.value=v;
        }
    }
    public String longestDiverseString(int a, int b, int c) {
       StringBuilder sb = new StringBuilder();
        List<Data> list = new ArrayList<>();
        list.add(new Data('a',a));
        list.add(new Data('b',b));
        list.add(new Data('c',c));
        Comparator<Data> comparator =(o1,o2)->{
            if(o1.value>o2.value){
                return -1;
            } else if(o1.value<o2.value){
                return 1;
            }
            return 0;
        };
        while (true) {
            list.sort(comparator);
            if (sb.length()==0) {
                if (list.get(0).value<=2) {
                    while (list.get(0).value-->0){
                        sb.append(list.get(0).s);
                    }
                    while (list.get(1).value-->0){
                        sb.append(list.get(1).s);
                    }
                    while (list.get(2).value-->0){
                        sb.append(list.get(2).s);
                    }
                    return sb.toString();
                }
                if(list.get(1).value<=0){
                    return "";
                }
                sb.append(list.get(0).s).append(list.get(0).s);
                sb.append(list.get(1).s);
                list.get(0).value-=2;
                list.get(1).value--;
                continue;
            }
            char lastChar = sb.charAt(sb.length()-1);
            int firstIndex =-1;
            for(int i=0;i<list.size();i++){
                if (list.get(i).s != lastChar){
                    firstIndex = i;break;
                }
            }
            int secondIndex =-1;
            for(int i=0;i<list.size();i++){
                if(i!=firstIndex){
                    secondIndex = i;break;
                }
            }

            if(list.get(firstIndex).value >= list.get(secondIndex).value && list.get(firstIndex).value>=2 && list.get(secondIndex).value>=1){
                sb.append(list.get(firstIndex).s).append(list.get(firstIndex).s).append(list.get(secondIndex).s);
                list.get(firstIndex).value-=2;
                list.get(secondIndex).value--;
                continue;
            } else if(list.get(firstIndex).value>=1 && list.get(secondIndex).value>=2){
                sb.append(list.get(firstIndex).s).append(list.get(secondIndex).s).append(list.get(secondIndex).s);
                list.get(firstIndex).value--;
                list.get(secondIndex).value-=2;
                continue;
            }
            int count =0;
            while (count<2 && list.get(firstIndex).value-->0 ){
                sb.append(list.get(firstIndex).s);
                list.get(firstIndex).value--;
                count++;
            }
            count =0;
            while (count<2&&list.get(secondIndex).value-->0){
                sb.append(list.get(secondIndex).s);
                list.get(secondIndex).value--;
                count++;
            }
            int third = -1;
            for(int i=0;i<list.size();i++){
                if(i!=firstIndex && i!=secondIndex){
                    third=i;
                }
            }
            count =0;
            while (count<2 && list.get(third).value-->0){
                sb.append(list.get(third).s);
                list.get(third).value--;
                count++;
            }
            break;
        }
        return sb.toString();
    }
}
```