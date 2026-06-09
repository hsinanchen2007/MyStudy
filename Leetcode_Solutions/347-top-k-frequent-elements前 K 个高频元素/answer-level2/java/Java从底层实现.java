```
class Solution {

    private interface Queue<E> {
	
        int getSize();
        boolean isEmpty();
        void enqueue(E e);
        E dequeue();
        E getFront();
    }

	private class Array<E> {
        private E[] data;
        private int size;
        private double resizeRatio = 0.75;
        
        public Array() {
            this(10);
            // TODO Auto-generated constructor stub
        }
        
        public Array(int capacity) {
            data = (E[])new Object[capacity];
            size = 0;
        }
        
        // 初始化传入一个数组，可以拷贝出一个一样的动态数组
        public Array(E[] arr) {
            data = (E[])new Object[arr.length];
            
            for (int i = 0; i < arr.length; i++) {
                data[i] = arr[i];
            }
            size = arr.length;
        }
        
        public int getSize() {
            return size;
        }
        
        public int getCapacity() {
            return data.length;
        }
        
        public boolean isEmpty() {
            return (size == 0);
        }
        
        public void add(int index, E e) {
            if (index > size || index < 0) 
            {
                throw new IllegalArgumentException("Add failed");
            }
            if (size == (int)(data.length*resizeRatio)) 
            {
                resize(2 * data.length);
            }
            for (int i = size - 1; i >= index; i--) 
            {
                data[i+1] = data[i];
            }
            data[index] = e;
            size ++;
        }

        public void addFirst(E e) {
            add(0, e);
        }
        
        public void addLast(E e) {
            add(size, e);
        }
        
        public E get(int index) {
            if (index < 0 || index > size) 
                throw new IllegalArgumentException("Get failed");
            return data[index];
        }
        
        public E getLast() {
            return get(size - 1);
        }
        
        public E getFirst() {
            return get(0);
        }
        
        public void set(int index, E e) {
            if (index < 0 || index > size) 
                throw new IllegalArgumentException("Get failed");
            data[index] = e;
        }
        
        public boolean  isExist(E e) {
            // TODO Auto-generated method stub
            for (int i = 0; i < size; i++) 
            {
                if (data[i].equals(e)) 
                {
                    return true;
                }
            }
            return false;
        }
        
        public int findIndex(E e) {
            for (int i = 0; i < size; i++) 
            {
                if (data[i].equals(e) ) 
                {
                    return i;
                }
            }
            return -1;
        }
        
        public E remove(int index) {
            if (index < 0 || index > size) 
                throw new IllegalArgumentException("Remove failed");
            E ret = data[index];
            for (int i = index + 1; i < size; i++) 
            {
                data[i-1] = data[i];
            }
            size --;
            data[size] = null;
            
            if (size == data.length / 4) 
            {
                resize(data.length/2);
            }
            return ret;
        }
        
        public E removeFirst() {
            return remove(0);
        }
        
        public E removeLast() {
            return remove(size - 1);
        }
        
        public void removeElement(E e) {
            int index = findIndex(e);
            if (index != -1) 
            {
                remove(index);
            }
        }
        
        // 交换索引为i和j位置上的元素
        public void swap(int i, int j) {
            if(i < 0 || i >= size || j < 0 || j >= size)
                throw new IllegalArgumentException("Wrong index!");
            
            E t = data[i];
            data[i] = data[j];
            data[j] = t;
        }
        
        @Override
        public String toString() {
            // TODO Auto-generated method stub
            StringBuilder res = new StringBuilder();
            res.append(String.format("Array: size = %d, capacity = %d\n", size, data.length));
            res.append('[');
            for (int i = 0; i < size; i++) {
                res.append(data[i]);
                if (i != size -1) 
                {
                    res.append(", ");
                }
            }
            res.append(']');
            return res.toString();
        }
        
        private void resize(int newCapacity) {
            // TODO Auto-generated method stub
            E[] newData = (E[])new Object[newCapacity];
            for (int i = 0; i < size; i++) 
            {
                newData[i] = data[i];
            }
            data = newData;
        }
    }

    private class MaxHeap<E extends Comparable<E>> {

        private Array<E> data;
        
        public MaxHeap(int capacity) {
            data = new Array<>(capacity);
        }
        
        public MaxHeap() {
            data = new Array<>();
        }
        
        // 初始化时将一个数组转化成最大堆
        public MaxHeap(E[] arr){
            data = new Array<>(arr);
            for (int i = parent(arr.length - 1); i >= 0 ; i--) {
                siftDown(i);
            }
        }
        
        // 返回堆中元素的个数
        public int size() {
            return data.getSize();
        }
        
        // 返回堆是否为空
        public boolean isEmpty() {
            return data.isEmpty();
        }

        // 私有辅助函数，返回完全二叉树的数组表示中，一个索引所表示的元素的父亲节点的索引值
        private int parent(int index) {
            if(index == 0)
                throw new IllegalArgumentException("Index-0 doesn't have parent!");
            return (index - 1) / 2;
        }
        
        // 私有辅助函数，返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引值
        public int leftChild(int index) {
            return (index * 2 + 1);
        }
        
        // 私有辅助函数，返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引值
        public int rightChild(int index) {
            return (index * 2 + 2);
        }
        
        // 向堆中添加元素
        public void add(E e) {
            data.addLast(e);
            siftUp(data.getSize() - 1);
        }
        
        // 私有辅助函数，用来上浮元素
        private void siftUp(int index) {
            
            while(index > 0 && data.get(parent(index)).compareTo(data.get(index)) < 0) {
                data.swap(parent(index), index);
                index = parent(index);
            }
            
        }
        
        // 看堆中最大的元素
        public E findMax() {
            if(data.getSize() == 0)
                throw new IllegalArgumentException("Heap is empty!");
            return data.get(0);
        }
        
        // 取出堆中的最大元素
        public E extractMax() {
            
            E ret = findMax();
            data.swap(0, data.getSize() - 1);
            data.removeLast();
            siftDown(0);
            
            return ret;
        }
        
        // 私有辅助函数，用来对元素下沉操作
        private void siftDown(int index) {
            
            while(leftChild(index) < data.getSize()) {
                
                // 比较出index位置元素的左右孩子中更大的那个
                // 先将maxChild索引初始化成左孩子
                int maxChild = leftChild(index);
                // 计算右孩子坐标
                int rightChild = rightChild(index);
                // 如果右孩子坐标合法，且右孩子比左孩子大，就更新maxChild等于rightChild，否则不处理，就是还为左孩子的坐标
                if(rightChild < data.getSize() &&
                        data.get(rightChild).compareTo(data.get(maxChild)) > 0)
                    maxChild = rightChild;
                // 此时data.get(maxChild)是左右孩子中最大的那个元素
                
                // 再比较根节点和左右孩子中最大节点的值谁大，如果根节点最大就满足了堆的定义，break，否则就进行下沉操作
                if(data.get(index).compareTo(data.get(maxChild)) >= 0)
                    break;
                
                //下沉
                data.swap(index, maxChild);
                index = maxChild;
            }
            
        }
        
        
        // replace:取出堆顶的最大元素，并且放入一个新元素e
        public E replace(E e) {
            
            E ret = findMax();
            data.set(0, e);
            siftDown(0);
            return ret;
            
        }
    }

    private class PriorityQueue<E extends Comparable<E>> implements Queue<E> {
        
        private MaxHeap<E> maxHeap;

        public PriorityQueue() {
            maxHeap = new MaxHeap<>();
        }

        @Override
        public int getSize() {
            return maxHeap.size();
        }

        @Override
        public boolean isEmpty() {
            return maxHeap.isEmpty();
        }

        @Override
        public void enqueue(E e) {
            maxHeap.add(e);
        }

        @Override
        public E dequeue() {
            return maxHeap.extractMax();
        }

        @Override
        public E getFront() {
            return maxHeap.findMax();
        }

    }


	private class Freq implements Comparable<Freq>{
		public int e, freq;

		public Freq(int e, int freq)
		{
			this.e = e;
			this.freq = freq;
		}
		// 定义比较方法，因为在该题中，我们要一直替换堆中最小的值，所以我们要在堆顶放最小值
		// 然而我们需要用最大堆实现，所以在实现Comparable接口时，我们定义数越小，优先级越高
		@Override
		public int compareTo(Freq o) {
			if(this.freq < o.freq)  // 正常应该是大返回1，但是这里我们定义越小越大（优先级越高）
				return 1;
			else if(this.freq > o.freq)
				return -1;
			else // 相等
				return 0;
		}
	}

	public List<Integer> topKFrequent(int[] nums, int k) {
		
		// map中的key是数组中的数，value是该数出现的频次
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		for(int num : nums)
		{
			if (map.containsKey(num)) 
				map.put(num, map.get(num) + 1);
			else 
				map.put(num, 1);
		}
		
		PriorityQueue<Freq> pq = new PriorityQueue<>();
		for (int key : map.keySet()) 
		{
			if (pq.getSize() < k) 
				pq.enqueue(new Freq(key, map.get(key)));
			else if(map.get(key) > pq.getFront().freq)
			{
				pq.dequeue();
				pq.enqueue(new Freq(key, map.get(key)));
			}
		}
		
		List<Integer> res = new LinkedList<Integer>();
		
		while(!pq.isEmpty())
		{
			res.add(pq.dequeue().e);
		}
		
		return res;
    }

}
```
