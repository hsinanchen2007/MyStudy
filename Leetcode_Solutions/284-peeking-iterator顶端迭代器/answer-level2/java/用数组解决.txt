```
    List<Integer> queue = new ArrayList<>();

    public PeekingIterator(Iterator<Integer> iterator) {
        while (iterator.hasNext()){
            queue.add(iterator.next());
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        if (queue.size()>0) return queue.get(0);
        return null;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        if (queue.size()>0){
            Integer result = queue.get(0);
            queue.remove(0);
            return result;
        }
        return null;
    }

    @Override
    public boolean hasNext() {
        return queue.size()==0?false:true;
    }
```

经过我的测试，在这个问题中，使用ArrayList的效率比LinkedList快1/3……