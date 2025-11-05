/****************************************************************************
** Meta object code from reading C++ file 'Robotcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/Robotcontroller.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Robotcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN15RobotControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto RobotController::qt_create_metaobjectdata<qt_meta_tag_ZN15RobotControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "RobotController",
        "joint1Changed",
        "",
        "joint2Changed",
        "joint3Changed",
        "clawOpenChanged",
        "statusChanged",
        "setJoint1",
        "v",
        "setJoint2",
        "setJoint3",
        "setClawOpen",
        "open",
        "presetHome",
        "presetDig",
        "presetDump",
        "joint1",
        "joint2",
        "joint3",
        "clawOpen",
        "status"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'joint1Changed'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'joint2Changed'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'joint3Changed'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'clawOpenChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'statusChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setJoint1'
        QtMocHelpers::SlotData<void(double)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 8 },
        }}),
        // Slot 'setJoint2'
        QtMocHelpers::SlotData<void(double)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 8 },
        }}),
        // Slot 'setJoint3'
        QtMocHelpers::SlotData<void(double)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 8 },
        }}),
        // Slot 'setClawOpen'
        QtMocHelpers::SlotData<void(bool)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 12 },
        }}),
        // Slot 'presetHome'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'presetDig'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'presetDump'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'joint1'
        QtMocHelpers::PropertyData<double>(16, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'joint2'
        QtMocHelpers::PropertyData<double>(17, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'joint3'
        QtMocHelpers::PropertyData<double>(18, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'clawOpen'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'status'
        QtMocHelpers::PropertyData<QString>(20, QMetaType::QString, QMC::DefaultPropertyFlags, 4),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<RobotController, qt_meta_tag_ZN15RobotControllerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject RobotController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15RobotControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15RobotControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15RobotControllerE_t>.metaTypes,
    nullptr
} };

void RobotController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<RobotController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->joint1Changed(); break;
        case 1: _t->joint2Changed(); break;
        case 2: _t->joint3Changed(); break;
        case 3: _t->clawOpenChanged(); break;
        case 4: _t->statusChanged(); break;
        case 5: _t->setJoint1((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->setJoint2((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->setJoint3((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->setClawOpen((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->presetHome(); break;
        case 10: _t->presetDig(); break;
        case 11: _t->presetDump(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (RobotController::*)()>(_a, &RobotController::joint1Changed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (RobotController::*)()>(_a, &RobotController::joint2Changed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (RobotController::*)()>(_a, &RobotController::joint3Changed, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (RobotController::*)()>(_a, &RobotController::clawOpenChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (RobotController::*)()>(_a, &RobotController::statusChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<double*>(_v) = _t->joint1(); break;
        case 1: *reinterpret_cast<double*>(_v) = _t->joint2(); break;
        case 2: *reinterpret_cast<double*>(_v) = _t->joint3(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->clawOpen(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->status(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setJoint1(*reinterpret_cast<double*>(_v)); break;
        case 1: _t->setJoint2(*reinterpret_cast<double*>(_v)); break;
        case 2: _t->setJoint3(*reinterpret_cast<double*>(_v)); break;
        case 3: _t->setClawOpen(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *RobotController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15RobotControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RobotController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RobotController::joint1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RobotController::joint2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RobotController::joint3Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void RobotController::clawOpenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void RobotController::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
