感觉最大的难点是分割字符串和删除多于的null。如果用C#、Java之类的，有强大的字符串操作函数，肯定写起来非常快。
```cpp
class Codec 
{
public:
    string serialize(TreeNode* root) 
    {
        const string null = "null,";
        string mid;
        queue<TreeNode*> q;
        q.push(root);
        while (q.empty() == false)
        {
            auto node = q.front();
            q.pop();
            if (node == nullptr)
            {
                mid += null;
            }
            else
            {
                mid += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        int length = mid.length();
        while (length >= null.size())
        {
            bool failed = false;
            int midStart = length - null.size();
            for (int i = null.size() - 1; i >= 0; --i)
            {
                if (mid[midStart + i] != null[i])
                {
                    failed = true;
                    break;
                }
            }

            if (failed)
            {
                break;
            }

            length -= null.size();
        }

        if (length != mid.size())
        {
            mid = mid.substr(0, length);
        }

        if (mid.empty() == false)
        {
            mid = mid.substr(0, mid.size() - 1);
        }

        return "[" + mid + "]";
    }

    TreeNode* deserialize(string data) 
    {
        data = data.substr(1, data.size() - 2);
        vector<TreeNode*> nodes;

        string::size_type prev_pos = 0;
        string::size_type pos = 0;
        while ((pos = data.find(',', pos)) != string::npos)
        {
            string sub = data.substr(prev_pos, pos - prev_pos);
            ++pos;
            prev_pos = pos;
            if (sub == "null")
            {
                nodes.push_back(nullptr);
            }
            else
            {
                nodes.push_back(new TreeNode(stoi(sub)));
            }
        }

        string last = data.substr(prev_pos);
        if (last.empty() == false)
        {
            if (last == "null")
            {
                nodes.push_back(nullptr);
            }
            else
            {
                nodes.push_back(new TreeNode(stoi(last)));
            }
        }

        int prevLevelTwiceIndex = 0;
        for (int i = 1; i < nodes.size(); ++i)
        {
            while (nodes[prevLevelTwiceIndex / 2] == nullptr)
            {
                ++prevLevelTwiceIndex;
            }

            if (prevLevelTwiceIndex % 2 == 0)
            {
                nodes[prevLevelTwiceIndex / 2]->left = nodes[i];
            }
            else
            {
                nodes[prevLevelTwiceIndex / 2]->right = nodes[i];
            }

            ++prevLevelTwiceIndex;
        }

        return nodes.empty() ? nullptr : nodes.front();
    }
};
```