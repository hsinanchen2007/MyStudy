```
private:
    multiset<int> heightSet; //保存高度集合（平衡搜索树）
    int max_height() {  //计算最高高度
        if (heightSet.empty()) {
            return 0;
        }
        return *heightSet.rbegin(); //（最后一个元素是最大元素）
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        
        vector<pair<int,int>> sweep_lines;  //保存扫描线
        
        for (auto b : buildings) {  //遍历建筑
            sweep_lines.emplace_back (b[0], b[2]);  //生成开始线
            sweep_lines.emplace_back (b[1], -b[2]); //生成结束线（用高度为负数区分）
        }
        
        sort (sweep_lines.begin(), sweep_lines.end(), [](pair<int, int>& line1, pair<int, int>& line2) { //lambda排序扫描线
            if (line1.first == line2.first) { //x相同，高度高的排在前面
                return line1.second > line2.second;
            }
            return line1.first < line2.first;
        });
        
        for (auto sweep_line : sweep_lines) {   //遍历排完序的扫描线
            int x = sweep_line.first;   //取横坐标
            int h = abs (sweep_line.second);    //取高度
            int is_start = (sweep_line.second > 0); //取开始线，结束线标记
            
            if (is_start) { //开始线
                if (h > this -> max_height()) { //当前高度大于已存所有高度，关键点
                    res.emplace_back (vector<int>{x, h});   //保存到结果
                }
                heightSet.insert (h);   //更新到高度表中
            }
            else {  //结束线
                heightSet.erase(heightSet.equal_range(h).first);    //当前高度就失效了，删除，而且只能删自己
                if (h > this -> max_height()) { //再来判断失效的高度大于已存所有高度（说明露出了新的关键点-当前的最大高度，前提是同一扫描线，按照高度从大到小排序）
                    res.emplace_back (vector<int>{x, this -> max_height()});    //保存新的关键点到结果
                }                
            }
        }
        return res;
    }
```
