```
    public int nextGreaterElement(int n) {
        String str = String.valueOf(n);
        char[] arr = str.toCharArray();
        PriorityQueue<Character> queue = new PriorityQueue<>();
        queue.offer(arr[arr.length - 1]);

        for (int i = arr.length - 1; i > 0; i--) {
            queue.offer(arr[i - 1]);

            // 出现满足条件的拐点
            if (arr[i] > arr[i - 1]) {
                int start = arr[i - 1], num = i;
                boolean flag = false;
                while (!queue.isEmpty()) {
                    
                    if (queue.peek() > start && !flag) {
                        arr[i - 1] = queue.poll();
                        flag = true;
                    } else {
                        arr[num++] = queue.poll();
                    }
                }
                
                str = new String(arr);
                if (Double.valueOf(str) > Math.pow(2, 31) - 1){
                    return -1;
                }
                return Integer.valueOf(str);

            }
        }

        return -1;
    }
```
