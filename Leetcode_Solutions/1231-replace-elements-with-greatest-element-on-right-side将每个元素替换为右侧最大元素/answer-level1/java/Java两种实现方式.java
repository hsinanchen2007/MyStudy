**解法1：用大顶堆记录最大值，从左往右扫，在堆中删掉当前位置的元素，然后将堆顶元素替换数组当前位置元素**
public int[] replaceElements(int[] arr) {
        Queue<Integer> queue = new PriorityQueue<>((o1, o2)->o2-o1);
        for(int num: arr){
            queue.add(num);
        }
        for(int i = 0, len = arr.length - 1; i < len; i++){
            queue.remove(arr[i]);
            arr[i] = queue.peek();
        }
        arr[arr.length - 1] = -1;
        return arr;
    }
**解法2：从右往左扫，每次都记录最大值，然后替换**
public int[] replaceElements(int[] arr) {
        int max = -1;
        for(int len = arr.length - 1; len >= 0; len --){
            int temp = arr[len];
            arr[len] = max;
            max = Math.max(max, temp);
        }
        return arr;
    }