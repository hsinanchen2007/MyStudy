```
public class LFUCache {
    //键 值 频率      元组写法
    Dictionary<int, (int, int)> dic;
    //负责记录的列表
    List<int> recList;
    //最大容量
    int max;
    public LFUCache(int capacity) {
        dic = new Dictionary<int, (int, int)>(capacity);
        recList = new List<int>();
        max = capacity;
    }

    //记录被操作的键的函数
    public void Record(int key){
        //不在字典中的直接返回
        if(!dic.ContainsKey(key)) return;
        //查看是否存在历史记录
        if(recList.Contains(key)){
            //删除旧的记录
            recList.Remove(key);
            //添加新的记录
            recList.Add(key);
        }else{
            //添加记录
            recList.Add(key);
        }
    }
    
    public int Get(int key) {
        //查看是否存在于字典中
        if(dic.ContainsKey(key)){
            //频率+1
            dic[key] = (dic[key].Item1, dic[key].Item2+1);
            //记录被操作的键
            Record(key);
            //返回按键对应的值
            return dic[key].Item1;
        }else{
            return -1;
        }
    }
    
    public void Put(int key, int value) {
        if(!dic.ContainsKey(key)){
            //查看是否超出最大容量
            if(dic.Count + 1 > max){
                int min = int.MaxValue;
                //寻找操作的最小频率
                foreach(var a in dic.Values){
                    if(a.Item2 < min){
                        min = a.Item2;
                    }
                }
                //查找第一个满足最小频率的键 (其实这里有一点歧义 按理说找'最近'应该倒着遍历 但是根据例子来看需要正着)
                for(int i = 0; i < recList.Count; i++){
                    if(dic[recList[i]].Item2 == min){
                        dic.Remove(recList[i]);
                        recList.RemoveAt(i);
                        break;
                    }
                }
                //查看删除元素后大小是否满足 (最大容量可能为0 所以需要判断)
                if(dic.Count + 1 <= max){
                    dic.Add(key, (value, 1));
                    Record(key);
                }
            }else{
                //添加新的键
                dic.Add(key, (value, 1));
                //记录行为
                Record(key);
            }
        }else{
            // 原来存在的键 更新他的值 并 将频率+1
            dic[key] = (value, dic[key].Item2+1);
            //记录行为
            Record(key);
        }
    }
}

```
