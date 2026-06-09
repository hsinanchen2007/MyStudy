### 解题思路
此处撰写解题思路

### 代码

```java
class TwoSum {

    /** Initialize your data structure here. */
    public List<Integer> list;
    public TwoSum() {
        list=new ArrayList<>();
    }
    
    /** Add the number to an internal data structure.. */
    public void add(int number) {
        list.add(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        Set<Integer> set=new HashSet<>();
        for(int i=0;i<list.size();i++)
        {
            int complement=value-(int) list.get(i);
            if(set.contains(complement))
                return true;
            set.add((int)list.get(i));
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