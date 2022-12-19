    1.使用HashMap记录下每一个数在原来数组的位置，利用LinkedList作为value值，因为一个数可能有多个值，并且保证链表是从大到小的，后面有用
    2.排序nums数组
    3.从大到小放入数据
    4.放入同时query检查前面的数量，用于求解键值对，在这里因为之前的链表是从大到小的，所以后一个拿出的值一定在上一个的前面，所以上一个与他相同的值，并不会影响到键值对从而导致结果错误

```
public int reversePairs(int[] nums) {
        HashMap<Integer, LinkedList<Integer>> map = new HashMap<>(nums.length);
        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(nums[i])) {
                LinkedList<Integer> linkedList = new LinkedList<Integer>();
                linkedList.add(i + 1);
                map.put(nums[i], linkedList);
            } else {
                map.get(nums[i]).addFirst(i + 1);
            }
        }
        Arrays.sort(nums);
        KenTree kenTree = new KenTree(nums.length);
        int res = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (i + 1 <= nums.length - 1 && nums[i] == nums[i + 1])
                continue;
            LinkedList<Integer> list = map.get(nums[i]);
            for (int index : list) {
                kenTree.update(index, 1);
                res += kenTree.sum(index - 1);
            }
        }
        return res;
    }

    class KenTree{
        Integer Capacity;
        int[] elements;

        public KenTree(Integer capacity) {
            Capacity = capacity;
            elements = new int[capacity+1];
        }

        private int lowbit(int num){
            return num&(-num);
        }

        public void update(int index,Integer data){
            for (int i = index;i<elements.length;i+=lowbit(i)){
                this.elements[i] += data;
            }
        }

        public int sum(int index){
            int res = 0;
            for(int i = index;i > 0;i-=lowbit(i)){
                res+=this.elements[i];
            }
            return res;
        }

        public int get(int index){
            return this.sum(index)-this.sum(index-1);
        }
    }
```
