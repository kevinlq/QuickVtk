#pragma once

#include <QOpenGLFunctions>
#include <QOpenGLFramebufferObject>

#include <vtkGenericOpenGLRenderWindow.h>

namespace quick {

    namespace Vtk {

        class FboRenderer;

        class FboOffscreenWindow : public vtkGenericOpenGLRenderWindow, protected QOpenGLFunctions {
        public:
            FboRenderer* QtParentRenderer;
            static auto New() -> FboOffscreenWindow*;
            virtual auto OpenGLInitState() -> void override;
            auto Render() -> void override;
            auto InternalRender() -> void;
            auto SetFramebufferObject(QOpenGLFramebufferObject*) -> void;
        protected:
            FboOffscreenWindow();
            ~FboOffscreenWindow();
        };
    }
}