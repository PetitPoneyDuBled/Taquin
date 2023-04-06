/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Taquin/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[369];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "on_quit_changed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 29), // "on_action_About_Mystic_Square"
QT_MOC_LITERAL(4, 58, 26), // "on_Button_new_game_clicked"
QT_MOC_LITERAL(5, 85, 10), // "moveButton"
QT_MOC_LITERAL(6, 96, 14), // "isPuzzleSolved"
QT_MOC_LITERAL(7, 111, 13), // "checkSolvable"
QT_MOC_LITERAL(8, 125, 12), // "QVector<int>"
QT_MOC_LITERAL(9, 138, 8), // "sequence"
QT_MOC_LITERAL(10, 147, 8), // "gridSize"
QT_MOC_LITERAL(11, 156, 17), // "connectAllButtons"
QT_MOC_LITERAL(12, 174, 15), // "setupPuzzleGrid"
QT_MOC_LITERAL(13, 190, 22), // "on_Button_save_clicked"
QT_MOC_LITERAL(14, 213, 22), // "on_Button_load_clicked"
QT_MOC_LITERAL(15, 236, 19), // "loadBackgroundImage"
QT_MOC_LITERAL(16, 256, 9), // "imagePath"
QT_MOC_LITERAL(17, 266, 23), // "on_actionWood_triggered"
QT_MOC_LITERAL(18, 290, 27), // "on_actionOriginal_triggered"
QT_MOC_LITERAL(19, 318, 23), // "on_actionTree_triggered"
QT_MOC_LITERAL(20, 342, 26) // "on_actionNetwork_triggered"

    },
    "MainWindow\0on_quit_changed\0\0"
    "on_action_About_Mystic_Square\0"
    "on_Button_new_game_clicked\0moveButton\0"
    "isPuzzleSolved\0checkSolvable\0QVector<int>\0"
    "sequence\0gridSize\0connectAllButtons\0"
    "setupPuzzleGrid\0on_Button_save_clicked\0"
    "on_Button_load_clicked\0loadBackgroundImage\0"
    "imagePath\0on_actionWood_triggered\0"
    "on_actionOriginal_triggered\0"
    "on_actionTree_triggered\0"
    "on_actionNetwork_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    2,   94,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    1,  103,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,
      19,    0,  108,    2, 0x08 /* Private */,
      20,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool, 0x80000000 | 8, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_quit_changed(); break;
        case 1: _t->on_action_About_Mystic_Square(); break;
        case 2: _t->on_Button_new_game_clicked(); break;
        case 3: _t->moveButton(); break;
        case 4: { bool _r = _t->isPuzzleSolved();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->checkSolvable((*reinterpret_cast< const QVector<int>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->connectAllButtons(); break;
        case 7: _t->setupPuzzleGrid(); break;
        case 8: _t->on_Button_save_clicked(); break;
        case 9: _t->on_Button_load_clicked(); break;
        case 10: _t->loadBackgroundImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_actionWood_triggered(); break;
        case 12: _t->on_actionOriginal_triggered(); break;
        case 13: _t->on_actionTree_triggered(); break;
        case 14: _t->on_actionNetwork_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
