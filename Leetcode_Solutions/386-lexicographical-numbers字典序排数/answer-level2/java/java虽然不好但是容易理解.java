
第i个元素的位置和谁有关(在谁后边):
  i%10!=0时i排在i-1的后边比如301,302
  i%10==0时i将排在i/10的后面比如1,10,100
所以插入i的时候无非就这两种插入方式

```

class Solution {
    ArrayList<Integer> list=new ArrayList<>();
    public List<Integer> lexicalOrder(int n) {
        list.add(1);
        int loc=1;
        for (int i = 2; i <=n ; i++) {
            if (i%10!=0){
                list.add(loc++,i);
            }
            else {
                loc=list.indexOf(i/10)+1;
                list.add(loc++,i);
            }

        }
        return list;
    }
}

```
