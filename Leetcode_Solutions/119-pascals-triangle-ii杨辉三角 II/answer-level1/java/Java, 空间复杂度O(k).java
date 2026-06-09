- 思想
- 第一层 【1】
- 求第二层  在列表尾部加个0 【1  0】，从尾部向前加（加上前一位得出本位）， 得出的二层 【1  1】
- 同理【1  1  0】  的出【1  2  1】
- 


```java
 public List<Integer> getRow(int rowIndex) {
        List<Integer> list = new ArrayList();
        list.add(1);
        int n = 1;
        while(n <= rowIndex){
            list.add(0);
            for(int i = list.size() - 1; i > 0; i--){
                list.set(i,list.get(i) + list.get(i - 1));
            }
            n++;
        }
        return list;
    }
```
