### BFS搜集最短距离为`level`的好友
 - 如题目中的图示，我和我的好友距离等于1，以`id`为起点，搜集距离为`level`的好友；
 - 使用广度优先搜索`(BFS)`的方式进行搜集，用`visited`数组标记是否搜集过该好友；
 - 初始时，向`bfsQueue`添加起始`id`和距离`0`，并打上标记，开始BFS;
 - 当距离小于`level`时，将该好友的`id`和距离添加到`bfsQueue`，并标记该好友已被搜集过；
 - 当距离等于`level`时，将该好友观看过的视频纳入统计；
 - 最后，将统计的视频的数据按照频率排序，频率相同的按照名字字典序排序。

```
class Solution {
public:
	vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
		unordered_map<string, int> videosMap;
		queue<pair<int, int>> bfsQueue;
		vector<bool> visited(watchedVideos.size(), false);
		bfsQueue.push(make_pair(id, 0));
		visited[id] = true;
		while (!bfsQueue.empty())
		{
			const pair<int, int>& frontPair = bfsQueue.front();
			int frontId = frontPair.first;
			int frontLevel = frontPair.second;
			if (frontLevel == level - 1)
			{
				for (size_t i = 0; i < friends[frontId].size(); ++i)
				{
					int friendId = friends[frontId][i];
					if (!visited[friendId])
					{
						visited[friendId] = true;
						for (size_t j = 0; j < watchedVideos[friendId].size(); ++j)
						{
							string video = watchedVideos[friendId][j];
							if (videosMap.find(video) == videosMap.end())
								videosMap[video] = 1;
							else
								++videosMap[video];
						}
					}
				}
			}
			else
			{
				for (size_t i = 0; i < friends[frontId].size(); ++i)
				{
					int friendId = friends[frontId][i];
					if (!visited[friendId])
					{
						bfsQueue.push(make_pair(friendId, frontLevel + 1));
						visited[friendId] = true;
					}
				}
			}

			bfsQueue.pop();
		}

		vector<pair<string, int>> videosVec;
		for (auto it = videosMap.begin(); it != videosMap.end(); ++it)
			videosVec.push_back(make_pair(it->first, it->second));
		sort(videosVec.begin(), videosVec.end(), cmp);

		vector<string> videos;
		for (auto it = videosVec.begin(); it != videosVec.end(); ++it)
			videos.push_back(it->first);

		return videos;
	}

	static bool cmp(const pair<string, int>& a, const pair<string, int>& b)
	{
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second < b.second;
	}
};
```
