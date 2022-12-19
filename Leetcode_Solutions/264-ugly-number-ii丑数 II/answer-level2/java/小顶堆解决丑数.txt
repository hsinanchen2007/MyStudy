### 解题思路
通过小顶堆解决丑数问题，顺便手撸一遍堆的插入删除方法

### 代码

```java
class Solution {
    // 维护小顶堆，先加后删，用一个数字表示加的位置，再用一个数字
    List<Long> heapArray;
    int count;
    public int nthUglyNumber(int n) {
        
        if ( n == 0 ) {
            return 0;
        }
        heapArray = new ArrayList<>();
        heapArray.add(1L); 
        count = 0;
        Long root = 1L;
        while(count != n-1) {
            root = upholdHeap(root);
           
            count++;
        }
        return root.intValue();
    }

    public Long upholdHeap(Long num) {
        Long num1 = num * 2;
        Long num2 = num * 3;
        Long num3 = num * 5;
        // 往小顶堆增加节点
        if (!heapArray.contains(num1)) {
            heapArray.add(num1);
            upshif(heapArray.size() - 1);
        }
        if (!heapArray.contains(num2)) {
            heapArray.add(num2);
            upshif(heapArray.size() - 1);
        }
        if (!heapArray.contains(num3)) {
            heapArray.add(num3);
            upshif(heapArray.size() - 1);
        }

        // 删除堆顶，将堆最后一个元素放到堆顶，且从上往下调整
        heapArray.set(0, heapArray.get(heapArray.size() - 1));
        heapArray.remove(heapArray.size() - 1);
        downshif(0);
        return heapArray.get(0);
    }
    // 从下往上调整顺序
    public void upshif(int child) {
        if (child < 1) {
            return;
        }
        // 满足左子节点且小于父节点，与父亲交换数据
        if (child%2 != 0 && heapArray.get(child)  < heapArray.get(child/2) ) {
            int parent = child/2;
            Long temp = heapArray.get(child) ;
            heapArray.set(child, heapArray.get(parent));
            heapArray.set(parent, temp);
            upshif(parent);
        }
        // 满足右子节点且小于父节点，与父亲交换数据
       if (child%2 == 0 && heapArray.get(child)  < heapArray.get(child/2 - 1)) {
            int parent = child/2 - 1;
            Long temp = heapArray.get(child) ;
            heapArray.set(child, heapArray.get(parent));
            heapArray.set(parent, temp);
            upshif(parent);
        }
    }
    // 从上往下调整,最后无法调整则删除此节点
    public void downshif(int root) {
        int lchild = root * 2 + 1;
        int rchild = root * 2 + 2;
        int minchild = 0;
        // 找到最小子节点
        if (lchild > heapArray.size() - 1) {
            return;
        } else if (rchild > heapArray.size() - 1){
            minchild = lchild;
        } else {
            if (heapArray.get(lchild) < heapArray.get(rchild)) {
                minchild = lchild; 
            } else {
                minchild = rchild;
            }
        }
        // 若比父亲小则交换
        if (heapArray.get(minchild) < heapArray.get(root)) {
            Long temp = heapArray.get(minchild);
            heapArray.set(minchild, heapArray.get(root));
            heapArray.set(root, temp);
            downshif(minchild);
        }
    }


}
```