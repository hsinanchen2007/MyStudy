1.定义map<int, pair<int, vector<int> > >
2.key为出现的数字， pair.first 存储数字出现次数，vector<int>存储数字的位置
3.获出现最大次数的key，vector<int>存储的末尾减去开头，哪个值最小，就是哪个
4.此算法比较浪费空间
还有很大的算法优化空间