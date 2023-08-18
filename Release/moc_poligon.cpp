/****************************************************************************
** Meta object code from reading C++ file 'poligon.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Drawing/poligon.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'poligon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Poligon_t {
    uint offsetsAndSizes[28];
    char stringdata0[8];
    char stringdata1[17];
    char stringdata2[16];
    char stringdata3[1];
    char stringdata4[16];
    char stringdata5[6];
    char stringdata6[9];
    char stringdata7[8];
    char stringdata8[16];
    char stringdata9[8];
    char stringdata10[13];
    char stringdata11[10];
    char stringdata12[8];
    char stringdata13[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Poligon_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Poligon_t qt_meta_stringdata_Poligon = {
    {
        QT_MOC_LITERAL(0, 7),  // "Poligon"
        QT_MOC_LITERAL(8, 16),  // "getPoligonPoints"
        QT_MOC_LITERAL(25, 15),  // "QList<QPointF>*"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 15),  // "getRotatingFlag"
        QT_MOC_LITERAL(58, 5),  // "bool*"
        QT_MOC_LITERAL(64, 8),  // "getMutex"
        QT_MOC_LITERAL(73, 7),  // "QMutex*"
        QT_MOC_LITERAL(81, 15),  // "getRotateNumber"
        QT_MOC_LITERAL(97, 7),  // "double*"
        QT_MOC_LITERAL(105, 12),  // "paintPoligon"
        QT_MOC_LITERAL(118, 9),  // "QPainter*"
        QT_MOC_LITERAL(128, 7),  // "painter"
        QT_MOC_LITERAL(136, 13)   // "rotatePoligon"
    },
    "Poligon",
    "getPoligonPoints",
    "QList<QPointF>*",
    "",
    "getRotatingFlag",
    "bool*",
    "getMutex",
    "QMutex*",
    "getRotateNumber",
    "double*",
    "paintPoligon",
    "QPainter*",
    "painter",
    "rotatePoligon"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Poligon[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    3, 0x0a,    1 /* Public */,
       4,    0,   51,    3, 0x0a,    2 /* Public */,
       6,    0,   52,    3, 0x0a,    3 /* Public */,
       8,    0,   53,    3, 0x0a,    4 /* Public */,
      10,    1,   54,    3, 0x0a,    5 /* Public */,
      13,    0,   57,    3, 0x0a,    7 /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 5,
    0x80000000 | 7,
    0x80000000 | 9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Poligon::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Poligon.offsetsAndSizes,
    qt_meta_data_Poligon,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Poligon_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Poligon, std::true_type>,
        // method 'getPoligonPoints'
        QtPrivate::TypeAndForceComplete<QList<QPointF> *, std::false_type>,
        // method 'getRotatingFlag'
        QtPrivate::TypeAndForceComplete<bool *, std::false_type>,
        // method 'getMutex'
        QtPrivate::TypeAndForceComplete<QMutex *, std::false_type>,
        // method 'getRotateNumber'
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        // method 'paintPoligon'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPainter *, std::false_type>,
        // method 'rotatePoligon'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Poligon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Poligon *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QList<QPointF>* _r = _t->getPoligonPoints();
            if (_a[0]) *reinterpret_cast< QList<QPointF>**>(_a[0]) = std::move(_r); }  break;
        case 1: { bool* _r = _t->getRotatingFlag();
            if (_a[0]) *reinterpret_cast< bool**>(_a[0]) = std::move(_r); }  break;
        case 2: { QMutex* _r = _t->getMutex();
            if (_a[0]) *reinterpret_cast< QMutex**>(_a[0]) = std::move(_r); }  break;
        case 3: { double* _r = _t->getRotateNumber();
            if (_a[0]) *reinterpret_cast< double**>(_a[0]) = std::move(_r); }  break;
        case 4: _t->paintPoligon((*reinterpret_cast< std::add_pointer_t<QPainter*>>(_a[1]))); break;
        case 5: _t->rotatePoligon(); break;
        default: ;
        }
    }
}

const QMetaObject *Poligon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Poligon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Poligon.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Poligon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
