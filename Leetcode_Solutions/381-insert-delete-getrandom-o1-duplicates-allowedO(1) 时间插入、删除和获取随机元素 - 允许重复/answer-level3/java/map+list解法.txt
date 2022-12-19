


    public static void main(String[] args) {
        RandomizedCollection collection = new RandomizedCollection();
        // 向集合中插入 1 。返回 true 表示集合不包含 1 。
        System.out.println(collection.insert(1));

        // 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
        System.out.println(collection.insert(1));

        // 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
        System.out.println( collection.insert(2));

        // getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
        System.out.println( collection.getRandom());

        // 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
        System.out.println( collection.remove(1));

        // getRandom 应有相同概率返回 1 和 2 。
        System.out.println( collection.getRandom());

    }
    private Map<Integer,List<Integer>> map = new HashMap<Integer, List<Integer>>();

    private List<Integer> list = new ArrayList<Integer>();

    /** Initialize your data structure here. */
    public RandomizedCollection() {

    }
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        list.add(val);
        return put(val,list.size() - 1);
    }

    private boolean put(int val,int index){
        boolean isNoRepeat = true;
        List<Integer> indexs = map.get(val);
        if(indexs == null){
            indexs = new ArrayList<Integer>();
            map.put(val,indexs);
        }else if(indexs.size() > 0){
            isNoRepeat = false;
        }
        indexs.add(index);
        return isNoRepeat;
    }
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        List<Integer> indexs = map.get(val);
        if(indexs == null || indexs.size() == 0){
            return false;
        }
        int index = indexs.get(0);
        indexs.remove(0);
        list.set(index,null);
        return true;
    }

    /** Get a random element from the collection. */
    public int getRandom() {
        if(list.size() == 0){
            return Integer.MIN_VALUE;
        }
        if(list.size() == 1){
            return list.get(0);
        }
        int retryNum = 0;
        while(retryNum++ < 3){
            Integer val = randomVal();
            if(val != null){
                return val;
            }
        }
        sortOut();
        return getRandom();
    }

    private Integer randomVal(){
        Random random = new Random();
        int randomIndex = random.nextInt(list.size());
        Integer val = list.get(randomIndex);
        if(val != null){
            return val;
        }
        return null;
    }
    /** 重新整理list和map中的元素 */
    private void sortOut(){
        map = new HashMap<Integer, List<Integer>>();
        List<Integer> temporaryList = new ArrayList<Integer>();
        for(int i = 0;i < list.size();i++){
            Integer val = list.get(i);
            if(val != null){
                temporaryList.add(val);
                put(val,temporaryList.size() - 1);
            }
        }
        list = temporaryList;
    }
 


思路：利用map存储值的下标，list存储元素，list用于随机获取参考权重，因为有删除，所以list的元素并不能直接删除，而是用null代替删除，在随机获取时，三次随机获取元素，若三次获取的元素都是null，则重新整理元素，删除null的值。

![QQ图片20190811093534.png](https://pic.leetcode-cn.com/62456038ea085cadcdd094f10d09755736d3fe1a325e184c7d5c0f4aeeba08a4-QQ%E5%9B%BE%E7%89%8720190811093534.png)

求大佬们如何优化