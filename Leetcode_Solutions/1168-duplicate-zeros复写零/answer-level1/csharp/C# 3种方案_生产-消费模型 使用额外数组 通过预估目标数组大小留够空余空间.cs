```C# []
        public void DuplicateZeros(int[] arr)
        {
            /*
             * 题目概述：复写 0
             * 
             * 思路：
             *  1.如果知道延伸到了哪个位置以后就到了数组边界的话,只要逆序写就可以了
             *  2.因为相当于是吧位置留出来了,所以就不怕空间不够了,这就是逆序回写的优势了,这个在其他的题目中见到过此种解决问题的思路
             *
             * 关键点：
             *
             * 时间复杂度：O(n)
             * 空间复杂度：O(1)
             */

            var slowIndex = 0;
            var fastIndex = 0;
            while (fastIndex < arr.Length)
            {
                var curValue = arr[slowIndex++];

                fastIndex++;
                if (curValue == 0)
                    fastIndex++;
            }

            var value = arr[--slowIndex];
            if (--fastIndex < arr.Length)
                arr[fastIndex] = value;
            if (value == 0)
                arr[--fastIndex] = value;

            while (slowIndex > 0)
            {
                var curValue = arr[--slowIndex];

                arr[fastIndex] = curValue;
                if (curValue == 0)
                    arr[--fastIndex] = curValue;
            }
        }

        public void DuplicateZeros(int[] arr)
        {
            /*
             * 题目概述：复写 0
             * 
             * 思路：
             *  1.函数本身没有返回值,但是希望通过引用的方式得到返回值,这个在编程中也是比较常用的手段了;
             *  2.题目并没有要求不能使用额外的空间,于是可以考虑在函数内部再新建一个数组存放数据结果,最后再往原来的数组上抄即可
             *
             * 关键点：数组
             *
             * 时间复杂度：O(n)
             * 空间复杂度：O(n)
             */

            var newArr = new List<int>(arr.Length);
            for (var arrIndex = 0; arrIndex < arr.Length && newArr.Count <= arr.Length; arrIndex++)
            {
                var curNum = arr[arrIndex];

                newArr.Add(curNum);
                if (curNum == 0 && newArr.Count <= arr.Length)
                    newArr.Add(curNum);
            }

            for (var i = 0; i < arr.Length; i++)
                arr[i] = newArr[i];
        }

        public void DuplicateZeros(int[] arr)
        {
            /*
             * 题目概述：复写 0
             * 
             * 思路：
             *  1.数组是定长的,需要在原数组上做修改,只要改了那么数组一定变长,紧接着就要截断
             *  2.考虑 生产-消费 模型,和双指针模型
             *  3.一个指针代表生产者,将从数组中读取到的数据写入到队列中
             *  4.一个指针代表消费者,从队列中读取数字然后写入到数组中
             *  5.生产者每次生产 2 个数据,直到上限
             *  5.消费者每次消费 1 个数据,遇到 0 的时候做特殊处理,即往数组中写入 2 次数据
             *
             * 关键点：数组 生产者-消费者 队列 双指针
             *
             * 时间复杂度：O(n)
             * 空间复杂度：O(n)
             */

            var queueTemp = new Queue<int>();
            var fastIndex = 0;
            var slowIndex = 0;
            while (slowIndex < arr.Length)
            {
                if (fastIndex < arr.Length)
                    queueTemp.Enqueue(arr[fastIndex++]);

                if (fastIndex < arr.Length)
                    queueTemp.Enqueue(arr[fastIndex++]);

                var curValue = queueTemp.Dequeue();

                arr[slowIndex++] = curValue;

                if (curValue == 0 && slowIndex < arr.Length)
                    arr[slowIndex++] = curValue;
            }
        }
```
