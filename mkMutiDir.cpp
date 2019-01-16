#include <QCoreApplication>
#include <QDir>
#include <QDebug>
QString mkMutiDir(const QString path){
    QDir dir(path);
    if ( dir.exists(path)){
        return path;
    }
    QString parentDir = mkMutiDir(path.mid(0,path.lastIndexOf('/')));
    QString dirname = path.mid(path.lastIndexOf('/') + 1);
    QDir parentPath(parentDir);
    if ( !dirname.isEmpty() )
        parentPath.mkpath(dirname);
    return parentDir + "/" + dirname;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString fileName = "d:/download/1234/abc/11/22/1234.txt";
    int pos = fileName.lastIndexOf("/");
    if(pos>=0)
    {
        QString innerDirPath = fileName.left( pos );
        qDebug() << mkMutiDir(innerDirPath);
    }
    return a.exec();
}
