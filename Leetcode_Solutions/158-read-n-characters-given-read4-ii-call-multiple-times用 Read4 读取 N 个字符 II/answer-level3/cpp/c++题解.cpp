```
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if (n <= 0 || buf == NULL)
	  return 0;

        int total_read = 0;
        int min_len = std::min(m_left, n);
        memcpy(buf, &m_buf[m_buf_pos], min_len);
        m_left -= min_len;
        if (m_left == 0) {
          m_buf_pos = 0;
        } else {
          m_buf_pos += min_len;
        }
        n -= min_len;
        total_read += min_len;

        int buf_pos = min_len;
        int ret = 0;
        while (n > 0) {
          ret = read4(m_buf);
          if (ret < 4 || n < 4)
            break;

          memcpy(&buf[buf_pos], m_buf, 4);	
          buf_pos += 4;
          n -= 4;
          total_read += 4;
        }

        if (n > 0) {
          int min_len = std::min(ret, n);
          memcpy(&buf[buf_pos], m_buf, min_len);
          m_left = ret - min_len;
          m_buf_pos = min_len;
          total_read += min_len;
        }

        return total_read;
  }
    
  Solution() {
      m_buf = new char[4];
      m_left = 0;
      m_buf_pos = 0;
  }

  ~Solution() {
     delete[] m_buf;
   }
    
  char *m_buf;
  int m_left;
  int m_buf_pos;
};
```