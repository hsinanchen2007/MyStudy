### 解题思路
根据给出的数组 初始化box类然后模仿人的行为一次次找盒子 找钥匙打开  跑的略慢 不过比较容易理解。 应该是第一个c#解吧

### 代码

```csharp
    public class Solution
    {
        private Dictionary<int, bool> box = new Dictionary<int, bool>();
        private Dictionary<int, bool> tmpbox = new Dictionary<int, bool>();
        private List<int> changekey = new List<int>();
        private Dictionary<int, bool> key = new Dictionary<int, bool>();
        public int MaxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes)
        {
            List<box> list = new List<box>();
            for (int i = 0; i < status.Length; i++)
            {
                var box = new box(candies[i], status[i], new List<box>(), new List<int>()) ;
                list.Add(box);
            }
            for (int i = 0; i < status.Length; i++)
            {
                foreach (var item in containedBoxes[i])
                {
                    list[i].boxes.Add(list[item]);
                }
                foreach (var item in keys[i])
                {
                    list[i].key.Add(item);
                }
            }

            for (int i = 0; i < initialBoxes.Length; i++)
            {
                box.Add(initialBoxes[i], false);
            }
            int count = 0;
            bool flag = true;
            while (flag) {
                flag = false;
                foreach (var item in box)
                {
                
                    if (item.Value == false) {
                        if (key.ContainsKey(item.Key)||status[item.Key]==1) {
                            
                            changekey.Add(item.Key);
                            count += candies[item.Key];
                            flag = true;
                            status[item.Key] = 2;
                            foreach (var itemb in containedBoxes[item.Key])
                            {
                                tmpbox.Add(itemb, false);
                            }
                            foreach (var itemk in keys[item.Key])
                            {
                                  if (!key.ContainsKey(itemk)) {
                                    key.Add(itemk, false);
                                }
                            }
                        }
                    }
                }
                foreach (var item in tmpbox)
                {
                    box.Add(item.Key, item.Value);
                }
                foreach (var item in changekey)
                {
                    box[item] = true;
                }
                tmpbox.Clear();
            }
            return count;
        }
    }

    public class box {
        public List<box> boxes;
        public List<int> key;
        public int status { get; set; }
        public int count { get; set; }
        public box(int count ,int status, List<box> boxes, List<int> key) {
            this.count = count;
            this.status = status;
            this.boxes = boxes;
            this.key = key;
        }
    }
```