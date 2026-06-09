#### 方法1 
文件和目录分别使用不同的2份Dict，方便独立处理文件元素以及文件夹元素
```py
# leetcode time     cost : 112 ms
# leetcode memory   cost : 13.7 MB
# solution 1, dir struct contains sub element of dict files and dirs.
class Dir:
    def __init__(self):
        self.dirs = {}
        self.files = {}

class FileSystem:

    def __init__(self):
        self.root = Dir()
        

    #def ls(self, path: str) -> List[str]:
    def ls(self, path):
        dir_struct = self.root
        files = []
        if path is not "/":
            path_list = path.split("/")
            # loop deeper until the last dir
            for i in range(1,len(path_list)-1):
                
                dir_struct = dir_struct.dirs[ path_list[i] ]
            # check if the input file is file item or dir item
            if (path_list[-1] in dir_struct.files):
                files.append(path_list[-1])    
                return files
            # otherwise the item is a dir item,get the dir name
            else:
                dir_struct = dir_struct.dirs[ path_list[-1] ]
        files = list(dir_struct.dirs.keys()) + list(dir_struct.files.keys())
        files.sort()
        return files
            

    def mkdir(self, path):
        dir_struct = self.root
        path_list = path.split("/")
        for i in range(1,len(path_list)):
            if path_list[i] not in dir_struct.dirs.keys():
                dir_struct.dirs[ path_list[i] ] = Dir()
            dir_struct = dir_struct.dirs[ path_list[i] ]

    def addContentToFile(self, filePath, content):
        dir_struct = self.root
        path_list = filePath.split("/")
        for i in range(1,len(path_list)-1):
            dir_struct = dir_struct.dirs[ path_list[i] ]
        if path_list[-1] in  dir_struct.files.keys():   
            dir_struct.files[ path_list[-1] ] = dir_struct.files[ path_list[-1] ] + content
        else:
            dir_struct.files[ path_list[-1] ] = "" + content
            

    def readContentFromFile(self, filePath: str) -> str:
        dir_struct = self.root
        path_list = filePath.split("/")
        for i in range(1,len(path_list)-1):
            dir_struct = dir_struct.dirs[ path_list[i] ]
        fileContent = dir_struct.files[ path_list[-1] ]
        return fileContent


# Your FileSystem object will be instantiated and called as such:
def main():
    obj = FileSystem()
    operation= ["FileSystem","ls","ls","mkdir","ls","ls","ls","ls","addContentToFile","readContentFromFile","ls"]
    words = [[],["/"],["/"],["/rsx"],["/rsx"],["/"],["/"],["/"],["/bxjzdc","iozcpr"],["/bxjzdc"],["/rsx"]]           
    # expect is [null,[],[],null,[],["rsx"],["rsx"],["rsx"],null,"iozcpr",[]]
    print(None)
    for i in range(1,len(operation)):
        print("operation: ",operation[i],",parameter: ",words[i][0])
        if len(words[i])>1:
            cmd = 'obj.'+operation[i]+"(%r,%r)" % (words[i][0],words[i][1])
        else:
            cmd = 'obj.'+operation[i]+"(%r)" % words[i][0]
        result = eval(cmd)
        print("result: ",result)
    
if __name__ =='__main__':
    main()
```

#### 方法2 
文件和目录使用同一份Dict，方便遍历文件夹下所有子元素
```py
# leetcode time     cost : 72 ms
# leetcode memory   cost : 13.7 MB
# solution 2, dir struct contains sub element iterm, iterm type is specified by the attribute isFile(similar as trie isEnd).
class FileSystemItem:
    def __init__(self):
        self.isfile = False
        self.items = {}
        # if the item is file,then use content to save data in file
        self.content = ""

class FileSystem:

    def __init__(self):
        self.root = FileSystemItem()
        

    #def ls(self, path: str) -> List[str]:
    def ls(self, path):
        itemObject = self.root
        files = []
        if path is not "/":
            path_list = path.split("/")
            # loop deeper until the last dir
            for i in range(1,len(path_list)):
                itemObject = itemObject.items[ path_list[i] ]
            # check if the input file is file item or dir item
            if (itemObject.isfile):
                files.append(path_list[-1])    
                return files
        
        # otherwise directly return all the items in this path
        files = list(itemObject.items.keys())
        files.sort()
        return files
            

    def mkdir(self, path):
        itemObject = self.root
        path_list = path.split("/")
        for i in range(1,len(path_list)):
            if path_list[i] not in itemObject.items.keys():
                itemObject.items[ path_list[i] ] = FileSystemItem()
            itemObject = itemObject.items[ path_list[i] ]

    def addContentToFile(self, filePath, content):
        itemObject = self.root
        path_list = filePath.split("/")
        for i in range(1,len(path_list)-1):
            itemObject = itemObject.items[ path_list[i] ]
            
        if path_list[-1] not in itemObject.items.keys():
            itemObject.items[ path_list[-1] ] = FileSystemItem()            
        fileObject = itemObject.items[ path_list[-1] ]
        
        fileObject.isfile = True
        fileObject.content = fileObject.content + content;
        
    def readContentFromFile(self, filePath):
        itemObject = self.root
        path_list = filePath.split("/")
        for i in range(1,len(path_list)-1):
            itemObject = itemObject.items[ path_list[i] ]
        fileObject = itemObject.items[ path_list[-1] ]
        return fileObject.content


# Your FileSystem object will be instantiated and called as such:
def main():
    obj = FileSystem()
    operation= ["FileSystem","mkdir","ls","ls","mkdir","ls","ls","addContentToFile","ls","ls","ls"]
    words = [[],["/goowmfn"],["/goowmfn"],["/"],["/z"],["/"],["/"],["/goowmfn/c","shetopcy"],["/z"],["/goowmfn/c"],["/goowmfn"]]          
    # expect is [null,null,[],["goowmfn"],null,["goowmfn","z"],["goowmfn","z"],null,[],["c"],["c"]]
    print(None)
    for i in range(1,len(operation)):
        print("operation: ",operation[i],",parameter: ",words[i][0])
        if len(words[i])>1:
            cmd = 'obj.'+operation[i]+"(%r,%r)" % (words[i][0],words[i][1])
        else:
            cmd = 'obj.'+operation[i]+"(%r)" % words[i][0]
        result = eval(cmd)
        print("result: ",result)
    
if __name__ =='__main__':
    main()  
```