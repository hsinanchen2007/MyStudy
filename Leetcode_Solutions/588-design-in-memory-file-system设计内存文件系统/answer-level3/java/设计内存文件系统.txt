#### 方法 1：使用独立的文件夹和文件列表 [Accepted]

我们从文件夹结构开始我们的讨论。根文件夹是整个文件结构的基础。每个文件夹包含两个哈希表，分别是 $dirs$ 和 $files$。$dirs$ 包含的数据格式为：$[(subdirectory_1\_name: subdirectory_{1\_structure})， (subdirectory_2\_name: subdirectory_{2\_structure})...]$ 。$files$ 包含的数据格式为：$[(file_1: file_{1\_contents})，(file_2: file_{2\_contents})...]$。这个文件夹结构在下面的两层文件结构中进行展示说明。

![image.png](https://pic.leetcode-cn.com/2352094226fec964a53944ab3d002b483261fb9134e30cf7a27dc8481b62aa9c-image.png)
{:align="center"}

现在我们来讨论一下我们怎么实现各种需要的指令。

1. `ls`：这个指令中，我们初始化一个文件夹指针 $t$，它指向根文件夹。我们将输入文件夹路径以 '/' 为依据划分开并得到每一层文件夹名字的数组 $d$。然后我们遍历文件树并更新 $t$ 指针让其指向当前的文件所代表的树节点。最后，我们要么停在最后一个文件夹里，或者停在一个文件上。如果输入最后一级是文件名字，我们只需要返回这个文件名。如果最后一级是文件夹，我们从它的 $dirs$ 哈希表中得到所有子文件夹的名字。类似的，我们可以从最后一个文件夹的 $files$ 哈希表中得到所有文件的列表。我们将两个列表接起来，排序后返回。

2. `mkdir`：就如 `ls` 一样，我们从根文件夹开始逐层遍历文件树。一旦我们在 `mkdir` 中遇到一个不存在的文件夹,我们在最后一个文件夹的 $dirs$ 结构中创建一个新的条目并把它的子文件夹列表初始化为空列表。我们持续这一过程直到我们到达最后一级目录。

3. `addContentToFile`：如 `ls` 命令一样，我们逐层遍历文件路径。当我们到达文件所在文件夹时，我们检查 $files$ 列表中是否已经存在 $file$ 文件。如果文件已经存在，我们把当前内容添加到该文件的末尾，在对应文件的 value 部分添加）。如果文件不存在，我们在当前文件夹的 $files$ 列表中添加一个新的条目并将它的内容初始化为当前内容。

4. `readContentFromFile`：像前面的情况一样，我们通过逐层遍历到达最后一层文件夹目录。在最后一层文件夹中，我们在 $files$ 键中找到文件名的条目，然后返回它对应的文件内容。

```Java []
public class FileSystem {
    class Dir {
        HashMap < String, Dir > dirs = new HashMap < > ();
        HashMap < String, String > files = new HashMap < > ();
    }
    Dir root;
    public FileSystem() {
        root = new Dir();
    }
    public List < String > ls(String path) {
        Dir t = root;
        List < String > files = new ArrayList < > ();
        if (!path.equals("/")) {
            String[] d = path.split("/");
            for (int i = 1; i < d.length - 1; i++) {
                t = t.dirs.get(d[i]);
            }
            if (t.files.containsKey(d[d.length - 1])) {
                files.add(d[d.length - 1]);
                return files;
            } else {
                t = t.dirs.get(d[d.length - 1]);
            }
        }
        files.addAll(new ArrayList < > (t.dirs.keySet()));
        files.addAll(new ArrayList < > (t.files.keySet()));
        Collections.sort(files);
        return files;
    }

    public void mkdir(String path) {
        Dir t = root;
        String[] d = path.split("/");
        for (int i = 1; i < d.length; i++) {
            if (!t.dirs.containsKey(d[i]))
                t.dirs.put(d[i], new Dir());
            t = t.dirs.get(d[i]);
        }
    }

    public void addContentToFile(String filePath, String content) {
        Dir t = root;
        String[] d = filePath.split("/");
        for (int i = 1; i < d.length - 1; i++) {
            t = t.dirs.get(d[i]);
        }
        t.files.put(d[d.length - 1], t.files.getOrDefault(d[d.length - 1], "") + content);
    }

    public String readContentFromFile(String filePath) {
        Dir t = root;
        String[] d = filePath.split("/");
        for (int i = 1; i < d.length - 1; i++) {
            t = t.dirs.get(d[i]);
        }
        return t.files.get(d[d.length - 1]);
    }
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * List<String> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * String param_4 = obj.readContentFromFile(filePath);
 */
```

**表现分析**

* `ls` 指令的时间复杂度是 $O\big(m+n+klog(k)\big)$。这里，$m$ 表示输入字符串的长度，我们需要遍历输入字符串一遍来分开各层文件夹的名字。$n$ 是 `ls` 输入参数的最深文件夹的深度。这个参数需要考虑的原因是我们需要在树结构上往下进入 $n$ 层。$k$ 是输入文件夹路径最后一层文件夹的条目数目（包括文件和子文件夹）。我们将这些名字排序需要 $klog(k)$ 的时间。

* `mkdir` 操作的时间复杂度是 $O(m+n)$。这里 $m$ 是输入字符串的长度。我们需要把输入字符串遍历一遍获得所有层级的文件夹名，$n$ 是 `mkdir` 输入的最后一层文件夹的深度。

* `addContentToFile` 和 `readContentFromFile` 函数的时间复杂度都是 $O(m+n)$。$m$ 是输入字符串的长度，$n$ 是最后一层文件夹的深度。

* 这种维护文件夹结构的优势是扩展性很好，可以很方便地增加更多指令。比方说，`rmdir` 移除一个给定的文件夹路径，我们只需要从指定文件夹所在的节点中从 $dirs$ 中删除相应的文件夹条目即可。

* 重命名文件夹和文件也非常容易，因为我们需要做的只是用新的名字创建一个新的文件夹结构或者文件并删除原本的条目即可。

* 将一个子文件夹从一个目录移到另一个目录页非常容易，因为我们只需要获取相应的子文件夹类并把它放在新的文件夹结构下即可。

* 在某个路径下只获取文件夹列表或者文件列表非常容易，因为我们用 $dirs$ 和 $files$ 分别维护了两个列表。

#### 方法 2：使用统一的文件夹文件列表 [Accepted]

这个方法与前一种方法的不同点在于现在文件夹数据结构只有一个统一的 $files$ 哈希表，它保存了当前路径下所有的文件和子文件夹。除此以外，每个条目都有一个变量 $isfile$，如果为 True 表示当前是一个文件，否则是一个文件夹。进一步的，因为我们将文件夹和文件统一保存，我们还需要一个 $content$ 的条目，如果 $isfile$ 为 True 那么它保存了当前文件的内容。对于子文件夹，$content$ 为空。

下图说明了上面例子中的前 2 层文件结构。

![image.png](https://pic.leetcode-cn.com/decd76ad724a7aad2477f0a03f3778c9afca092a04f9c0b2a030df7cae8f879b-image.png)

实现所有命令的方法与上一种解法一致，除了在 `addContentToFile` 和 `mkdir` 操作中我们对文件夹和文件的操作都需要在同一个 $files$ 哈希表中进行。进一步的，对于 `ls`，我们不需要分别从文件夹列表和文件列表中获取条目名字，因为它们现在用同一个数据结构维护。

```Java []
public class FileSystem {
    class File {
        boolean isfile = false;
        HashMap < String, File > files = new HashMap < > ();
        String content = "";
    }
    File root;
    public FileSystem() {
        root = new File();
    }

    public List < String > ls(String path) {
        File t = root;
        List < String > files = new ArrayList < > ();
        if (!path.equals("/")) {
            String[] d = path.split("/");
            for (int i = 1; i < d.length; i++) {
                t = t.files.get(d[i]);
            }
            if (t.isfile) {
                files.add(d[d.length - 1]);
                return files;
            }
        }
        List < String > res_files = new ArrayList < > (t.files.keySet());
        Collections.sort(res_files);
        return res_files;
    }

    public void mkdir(String path) {
        File t = root;
        String[] d = path.split("/");
        for (int i = 1; i < d.length; i++) {
            if (!t.files.containsKey(d[i]))
                t.files.put(d[i], new File());
            t = t.files.get(d[i]);
        }
    }

    public void addContentToFile(String filePath, String content) {
        File t = root;
        String[] d = filePath.split("/");
        for (int i = 1; i < d.length - 1; i++) {
            t = t.files.get(d[i]);
        }
        if (!t.files.containsKey(d[d.length - 1]))
            t.files.put(d[d.length - 1], new File());
        t = t.files.get(d[d.length - 1]);
        t.isfile = true;
        t.content = t.content + content;
    }

    public String readContentFromFile(String filePath) {
        File t = root;
        String[] d = filePath.split("/");
        for (int i = 1; i < d.length - 1; i++) {
            t = t.files.get(d[i]);
        }
        return t.files.get(d[d.length - 1]).content;
    }
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * List<String> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * String param_4 = obj.readContentFromFile(filePath);
 */
```


**表现分析**

* `ls` 的时间复杂度是 $O\big(m+n+klog(k)\big)$。这里 $m$ 是输入字符串的长度，我们需要扫描输入字符串一次并获得每一层的文件名。$n$ 是最后一层文件夹的深度，我们需要进入 $n$ 层的文件树以到达最后一层文件所在路径。$k$是最后一层的文件和文件夹总数目。我们需要将它们排序，所以需要 $klog(k)$ 的时间。

* `mkdir` 时间复杂度是 $O(m+n)$，这里 $m$ 是输入字符串的长度，$n$ 是最后一层文件夹的深度。

* `addContentToFile` 和 `readContentFromFile` 操作的时间复杂度都是 $O(m+n)$。$m$ 是输入字符串的长度，$n$ 是最后一层文件夹在文件树中的深度。

* 使用这种维护文件结构的优势是很容易添加更多指令。比方说，`rmdir` 删除一个文件夹的指令只需要从列表中删除相应的条目。

* 重命名文件或者文件夹非常容易，因为我们只需要以新名字创建一个新的文件夹结构或者文件并删除原本的条目即可。

* 从一个路径移动子文件夹到另一个路径也很容易，因为我们需要做的只是获得相应子文件夹类的地址，然后在新文件路径下赋新的值。

* 如果文件夹数目非常大，我们会因为 $isfile$ 和 $content$ 浪费多余的空间，这部分空间在方法 1 中不会存在。

* 这个方法的一个问题是如果我们只想要给定路径中文件夹的列表，而不是文件的列表，访问将会变得低效。我们需要遍历当前文件夹所有内容一遍并检查是否是文件夹，才能得到我们想要的数据。
