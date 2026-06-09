用一个队列将需要覆写的元素暂时保存起来，遇到0时就将0加入队列，当队列不为空时则做交换并入列
```
class Solution {
    public void duplicateZeros(int[] arr) {
        LinkedList<Integer> buf = new LinkedList<>();
        for(int i=0;i<arr.length;i++) {
            if(arr[i] == 0) {
                buf.offer(0);
            }
            if(!buf.isEmpty()) {
                buf.offer(arr[i]);
                arr[i] = buf.poll();
            }
        }
        return;
    }
}
```
