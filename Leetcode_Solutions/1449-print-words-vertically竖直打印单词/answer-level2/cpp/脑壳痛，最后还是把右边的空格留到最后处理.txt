class Solution {
public:
	vector<string> printVertically(string s) {
		vector<string>m_abc;
		int m_len = s.length();//s.size()
		int m_len1 = 0, m_word = 0;
		for (int i = 0; i < m_len; i++) {
			if (s[i] != ' ') {//检测到单词
				if (++m_len1 > m_abc.size()) {
					m_abc.push_back("");
					int len = m_abc.size() - 1;
					if (m_len1 >= len & len >= 1 & m_word>0) {
						for (int j = 0; j<m_word; j++) {
							m_abc[len] = " " + m_abc[len];
						}
					}
				}
				m_abc[m_len1 - 1] += s[i];
			}
			else {
				int index = 1;
				for (int m = m_len1; m < m_abc.size(); m++) {
					if (index == 1) {
						for (int j = i + 1; j < m_len; j++)
						{
							if (s[j] != ' ') { index++; break; }
							else index = 0;

						}
					}
					if (index>1)m_abc[m] += " ";
				}
				m_len1 = 0;//单词结束 
				m_word++;
			}
		}
		for (int i = 0; i < m_abc.size(); i++) {
			while (m_abc[i][m_abc[i].size() - 1] == ' ') { m_abc[i].erase(m_abc[i].begin() + m_abc[i].size() - 1); }
		}
		return m_abc;
	}
};