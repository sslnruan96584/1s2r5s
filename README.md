# 如你所见这是个加密解密文本的工具（你就说他能不能加密吧）
###### bbll:
基于代码原因，该工具对文本进行加密解密后文本末尾会出现些许乱码  
（若要删去乱码，以我垃圾的代码功底来说仅能对照未加密前的文本进行行长度限制）  
（附：也可能是代码有些许问题，不太能理解为什么一个字符异或运算后还能多出来的）  
但此工具确实能够进行基础的加密与解密  
实现途经：异或运算两次后会将文本复原实现基础的对称密钥  
  
该行以下才是正文

## 构建方法：
#### 首先将整个仓库下载或克隆到计算机中
```bash
git clone git@github.com:sslnruan96584/1s2r5s.git
#下载仓库到电脑中
#下载完成后，你会得到一个名字叫 1s2r5s 的文件夹
#不要问为什么这么叫它 问就是懒得改qaq
#能用就行
```

```bash
cd 1s2r5s
cd code
#创建一个build文件夹用于外部构建
sudo mkdir build
sudo chmod go+rwx build
#更改下文件夹权限
cd build
cmake -DCMAKE_INSTALL_PREFIX=/temp/Crypto ..
make
sudo make install
#运行完后去跟目录下赵到temp文件夹依次点进去
#/temp/Crypto/share/bin
```

```bash
#打开终端
./CryptoTool
#直接在终端执行就好
```

```bash
#由于创建了文件夹到根目录，废物的我自然要给出删除代码，以示尊敬
cd /
sudo rm -rf temp

#删除完成qaq
```

