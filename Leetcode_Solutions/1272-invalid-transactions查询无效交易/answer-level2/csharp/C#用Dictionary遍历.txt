```
class structItem
    {
        public string name { get; set; }
        public string city { get; set; }
        public int price { get; set; }
        public int time { get; set; }
        public string itemAll { get; set; }
        public int flag { get; set; }//标志位 是否已经添加到数组中 1未加 0已加
        public string guid { get; set; }
    }

public class Solution {
    public IList<string> InvalidTransactions(string[] transactions) {
        Dictionary<string, List<structItem>> dic = new Dictionary<string, List<structItem>>();
            List<string> li = new List<string>();//结果集
            foreach (string item in transactions)
            {
                string[] str = item.Split(',');
                structItem dicVal = new structItem();
                dicVal.name = str[0];
                dicVal.time = Convert.ToInt32(str[1]);
                dicVal.price = Convert.ToInt32(str[2]);
                dicVal.city = str[3];
                dicVal.itemAll = item;
                dicVal.flag = 1;
                dicVal.guid = Guid.NewGuid().ToString();
                //时间比较
                if (dic.ContainsKey(str[0]))
                {
                    foreach (structItem dicVal1 in dic[str[0]])
                    {
                        int timeflag = Convert.ToInt32(str[1]);
                        if (Math.Abs(dicVal1.time - Convert.ToInt32(str[1])) <= 60 && (dicVal1.city != str[3]))
                        {
                            if (dicVal1.flag == 1)
                            {
                                dicVal1.flag = 0;
                                li.Add(dicVal1.itemAll);
                            }
                            if (dicVal.flag == 1)
                            {
                                li.Add(dicVal.itemAll);
                                dicVal.flag = 0;
                            }
                        }
                    }
                    dic[str[0]].Add(dicVal);
                }
                //价格比较
                if ((Convert.ToInt32(str[2]) > 1000)&&(dicVal.flag==1))
                {
                    li.Add(item);
                    dicVal.flag = 0;
                    if (dic.ContainsKey(str[0]))
                    {
                        dic[str[0]].Add(dicVal);
                    }
                    else
                    {
                        dic.Add(str[0],new List<structItem> { dicVal });
                    }
                }
                else if (dicVal.flag==1)
                {
                    if (dic.ContainsKey(str[0]))
                    {
                        dic[str[0]].Add(dicVal);
                    }
                    else
                    {
                        dic.Add(str[0], new List<structItem> { dicVal });
                    }
                }
            }
            return li;
    }
}

```
