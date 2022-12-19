### 解题思路
此处撰写解题思路

### 代码

```java
class TwoSum {
    List<Integer> l ;
    /** Initialize your data structure here. */
    public TwoSum() {
        l = new ArrayList<>();
    }
    
    /** Add the number to an internal data structure.. */
    public void add(int number) {
        int s0 = 0;
        int s1 = l.size();
        while(s0!=s1){
            int idx = (s1+s0)/2;
            if(l.get(idx)>number){
                s1 = idx;
            }else{
                s0=idx+1;
            }
        }
        l.add(s0,number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        for(int i=0,j=l.size()-1;i<j;){
            int k = l.get(j)+l.get(i)-value;
            if(k==0)
                return true;
            else if (k>0){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */
```